// leetcode 1027
// Longest Arithmetic Subsequence 

// 给定一个数组，我们希望从里面选出一些元素组成等差数列
// 我们想知道能选出来的最长的等差子序列的长度是多少
// 由于等差数列至少需要两个元素才能确定，所以相比于其他题目
// 我们需要考虑二维动态规划
// 考虑dp[i][j]是以dp[i] dp[j] 作为等差数组的后两项
// 那么公差就是d = a[j] - a[i]
// 前一项的值应该是val=2*a[i] - a[j]
// 所以我们可以在前面尝试找到是否存在一个值为val的元素
// dp[i][j] = max(dp[i][j], dp[k][i] + 1)
// 如果有多个值为val的元素，那么我们需要最右侧的那个

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        // 定义dp[i][j] 是以a[i], a[j]作为等差数组的最后两个的长度
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 2));
        // 利用一个map来记录元素值的位置，从而快速查找是否有满足条件的元素
        unordered_map<int, int> pos;
        int ans = 2;
        
        // i = 0..<n-1
        //   j = i+1 .. <n
        for(int i=0; i<n-1; i++) {
            for(int j=i+1; j<n; j++) {
                // 尝试以i,j作为后两项,那么应该有prev
                int prev = 2*nums[i] - nums[j];
                // 如果存在prev的话, 
                if (pos.count(prev) > 0) dp[i][j] = max(dp[i][j], dp[pos[prev]][i] + 1);
                ans = max(ans, dp[i][j]);
            }
            pos[nums[i]] = i;
        }
        return ans;
    }
};