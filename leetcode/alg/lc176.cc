// leetcode 176
// Largest Number 
// 给定一个数组，通过重排数组得到一个最大的数
// 这道题利用将数字转换为字符串，然后比较两个字符串的拼接方式

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        
        for(int i=0; i<nums.size(); i++) arr.push_back(to_string(nums[i]));
        
        sort(arr.begin(), arr.end(), [](const string& s1, const string& s2){
            return s1 + s2 > s2 + s1;
        });
        
        if (arr[0] == "0") return "0";
        
        string ans;
        
        for(int i=0; i<arr.size(); i++) ans += arr[i];
        
        return ans;
    }
};