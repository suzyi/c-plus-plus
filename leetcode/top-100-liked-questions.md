### Top 100 Liked Questions
solved: 1, 3, 19, 20, 

1. Two Sum
```
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
```
```
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2);
        int stop = 0;
        for(int i=0; i<nums.size()-1; i++) {
            for(int j=i+1; j<nums.size(); j++) {
                if(nums[i]+nums[j]==target) {
                    ans[0]=i;
                    ans[1]=j;
                    stop=1;
                    break;
                }
            }
        if(stop==1) {
            break;
        }
        }
        return ans;
    }
};
```
3. Longest Substring Without Repeating Characters

Given a string, find the length of the longest substring without repeating characters.
```
Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3.
```
+ hint: i<=j, the number of the char s[i] in the string s[i:j] is myMap[s[i]] and the number of the char s[j] in the string s[i:j] is myMap[s[j]].
+ example: s="abcabcbb"
  + "a"->"ab"->"abc"->"abca"->"bca"->"bcab"->"cab"->"cabc"->"abc"->"abcb"->"bcb"->"cb"->"cbb"->"bb"->"b"
```
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        unordered_map<char, int> myMap;
        for(int i=0, j=0; j<s.size(); j++) {
            myMap[s[j]]++;
            while(myMap[s[j]]>1) myMap[s[i++]]--;
            ans = max(ans, j-i+1);
        }
        return ans;
    }
};
```
19. Remove Nth Node From End of List
```
Given a linked list, remove the n-th node from the end of list and return its head.
Example: Given linked list: 1->2->3->4->5, and n = 2. After removing the second node from the end, the linked list becomes 1->2->3->5.
```
+ `fast` pointer points to the node which is N step away from the to_be_delete node. `slow` pointer points to the to_be_delete node.

The algorithms is described as below:
+ Firstly, move fast pointer N step forward.
+ Secondly,move fast and slow pointers simultaneously one step a time forward till the fast pointer reach the end, which will cause the slow pointer points to the previous node of the to_be_delete node.
+ Finally, slow->next = slow->next->next.
```
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) 
            return nullptr;
        ListNode new_head(-1);
        new_head.next = head;
        ListNode *slow = &new_head, *fast = &new_head;
        for(int i=0; i<n; i++) {
            fast = fast->next;
        }
        while(fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode *node_to_be_delete = slow->next;
        slow->next = slow->next->next;
        delete node_to_be_delete;
        return new_head.next;
    }
};
```
20. Valid Parentheses

Given a string containing just the characters '(', ')', '{', '}', '[', ']', determine if the input string is valid.
```
Input: "()[]{}"
Output: true

Input: "(]"
Output: false
```
```
class Solution {
public:
    bool isValid(string s) {
        stack<char> a;
        for(char &c:s) {
            switch(c) {
                case '(':
                case '[':
                case '{': a.push(c); break;
                case ')': if(a.empty() || a.top()!='(') return false; else a.pop(); break;
                case ']': if(a.empty() || a.top()!='[') return false; else a.pop(); break;
                case '}': if(a.empty() || a.top()!='{') return false; else a.pop(); break;
            }
        }
        return a.empty();
    }
};
```
49. Group Anagrams

Given an array of strings, group anagrams together.
```
Example: Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[ ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]]
```
```
algorithm:
str = "eat";
t = str;
sort(t.begin(), t.end()); // then t = "aet";
res["aet"] = "eat";
```
```
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;
        for(string str:strs) {
            string t = str;
            sort(t.begin(), t.end());
            res[t].push_back(str);
        }
        
        vector<vector<string>> ans;
        for(auto tmp:res) {
            ans.push_back(tmp.second);
        }
        return ans;
    }
};
```
