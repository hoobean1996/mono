// leetcode 487
// Max Consecutive Ones II

// 最大的连续的0，滑动窗口 
// 允许翻转两个0
// 维护一个[l..r]的滑动窗口，和该区间的0的个数
// 如果超过了，就需要移动左指针来使得区间还是满足这个性质即可
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int l = 0;
        int r = 0;
        int zeros = 0;
        
        while(r < nums.size()) {
            if (nums[r] == 0) zeros ++;
            
            while(zeros == 2) {
                if (nums[l] == 0) zeros --;
                l ++;
            }
            
            ans = max(ans, r - l + 1);
            r ++;
        }
        
        return ans;
    }
};