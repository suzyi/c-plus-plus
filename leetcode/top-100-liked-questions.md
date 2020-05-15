### Top 100 Liked Questions
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
