### Top 100 Liked Questions
solved: 
+ 1~100: 1, 3, 19, 20, 49, 70, 94, 96, 
+ 101~200: 136, 169, 
+ 201~300:

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
70. Climbing Stairs

You are climbing a stair case. It takes n steps to reach to the top. Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.
```
Example 1: Input: 2, Output: 2
```
```
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(2, 1);
        dp[1] = 2;
        for(int i=2; i<n; i++) {
            dp.push_back(dp[i-2]+dp[i-1]);
        }
        return dp[n-1];
    }
};
```
94. Binary Tree Inorder Traversal

Given a binary tree, return the inorder traversal of its nodes' values.
```
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode *> todo;
        vector<int> ans;
        while(root || !todo.empty()) {
            while(root) {
                todo.push(root);
                root = root->left;
            }
            root = todo.top();
            todo.pop();
            ans.push_back(root->val);
            root = root->right;
        }
        return ans;
    }
};
```
96. Unique Binary Search Trees

Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?
```
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(3, 1);
        dp[2] = 2;
        for(int i=3; i<=n; i++) {
            int tmp = 0;
            for(int j=0; j<i; j++) {
                tmp += dp[j]*dp[i-1-j];
            }
            dp.push_back(tmp);
        }
        return dp[n];
    }
};
```
136. Single Number

Given a non-empty array of integers, every element appears twice except for one. Find that single one.
```
Example: Input: [4,1,2,1,2], Output: 4
```
```
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans;
        unordered_map<int, int> mp;
        for(int tmp: nums) {
            mp[tmp] += 1;
        }
        for(auto tmp: mp) {
            if(tmp.second==1) ans = tmp.first;
        }
        return ans;
    }
};
```
169. Majority Element

Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times. You may assume that the array is non-empty and the majority element always exist in the array.
```
Example 1: Input: [3,2,3], Output: 3
```
```
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> ans;
        for(auto t: nums) {
            mp[t]++;
        }
        
        for(auto s: mp) {
            if(s.second>nums.size()/2) ans.push_back(s.first);
        }
        return ans[0];
    }
};
```
416. Partition Equal Subset Sum
```
Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Note: Each of the array element will not exceed 100. The array size will not exceed 200. 

Example 1: Input: [1, 5, 11, 5], Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].

Example 2: Input: [1, 2, 3, 5], Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
```
+ This problem is equavelent to finding a subset of nums, denoted as U, such that `sum(U)=sum(nums)/2`
  + Proof: Suppose the set nums is divided into two disjoint sets, denoted as U and V, then the union of U and V equals to nums. In addition, `sum(U)=sum(V)`, according to the description of the problem. Therefore, `sum(U)=sum(V)=sum(nums)/2`.
```
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int target = accumulate(nums.begin(), nums.end(), 0);
        if(target%2==1) return false;
        else target = target/2;
        
        vector<int> vec(target+1);
        vec[0] = 1;
        for(int i=0; i<nums.size(); i++) {
            for(int j=target; j>=nums[i]; j--) {
                vec[j] = vec[j] || vec[j-nums[i]];
            }
        }
        
        return vec[target];
    }
};
```
494. Target Sum

```
You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.
Example 1:Input: nums is [1, 1, 1, 1, 1], S is 3. Output: 5 
Explanation: 
-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.
```
+ Suppose the set `nums=[a1, a2, ..., an]` is divided into two disjoint subsets P (for positive sysmbol) and N (for negtive sysmbol). For example, if `nums = [1, 2, 3, 4]` and `target=2`, then P and N could be `P = [2, 4]` and `N = [1, 3]`.
+ The problem is equavelent to answering how many subsets, denoted as `P`, do we have such that `sum(P)=(sum(nums)+target)/2`?
  + Proof: Since `sum(P)-sum(N) = target` and `sum(P)+sum(N) = sum(nums)`, then we have `sum(P)=(sum(nums)+target)/2`.
```
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for (auto n : nums) sum += n;
        if(abs(S)>sum || (sum+S)%2==1) return 0;
        int target = (sum+S)/2;
        
        vector<int> vec(target+1);
        vec[0] = 1;
        for(int i=0; i<nums.size(); i++) {
            for(int j=target; j>=nums[i]; j--) {
                vec[j] = vec[j] + vec[j-nums[i]];
            }
        }
        
        return vec[target];
    }
};
```
560. Subarray Sum Equals K

```
Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.
Example 1: Input:nums = [1,1,1], k = 2, Output: 2
```
+ Time Limit Exceeded
```
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        for(int i=1; i<nums.size(); i++) nums[i] += nums[i-1];
        nums.insert(nums.begin(), 0);
        
        int ans=0;
        for(int i=1; i<nums.size(); i++) {
            for(int j=0; j<i; j++) {
                if(nums[i]-nums[j]==k) ans++;
            }
        }
        
        return ans;
    }
};
```
560. Subarray Sum Equals K
```
Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.
Example 1: Input:nums = [1,1,1], k = 2 Output: 2
```
```
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans=0, sum=0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        
        for(int i=0; i<nums.size(); i++) {
            sum += nums[i];
            ans += mp[sum-k];
            mp[sum] ++;
        }
        
        return ans;
    }
};
```
