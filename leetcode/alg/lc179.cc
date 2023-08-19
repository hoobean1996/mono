// leetcode 179
// largest number 
// 给定一个数字数组，需要用他们拼出一个最大数字的字符串

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        
        for(int i=0; i<nums.size(); i++) arr.push_back(to_string(nums[i]));
        
        // 对于两个字符串的排序，选择降序拼接的方法
        sort(arr.begin(), arr.end(), [](const string& s1, const string& s2){
            return s1 + s2 > s2 + s1;
        });
        
        if (arr[0] == "0") return "0";
        
        string ans;
        
        for(int i=0; i<arr.size(); i++) ans += arr[i];
        
        return ans;
    }
};