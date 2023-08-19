// leetcode 718
// Maximum Length of Repeated Subarray
// 给定两个数组，我们想要求得同时出现在两个数组中的最大子数组的长度

// 给定两个数组，找到出现在两个数组中的最大子数组
// 定义dp[i][j]是A[i:] 和 B[j:]的最大子数组长度
// dp[i][j] = dp[i+1][j+1] + 1 如果A[i] == B[i] 
// 否则就是0
// 时间复杂度 O (m*n)
// 空间复杂度 O (m*n)
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;

        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));

        for (int i = nums1.size() - 1; i >= 0; i--) {
            for (int j = nums2.size() - 1; j >= 0; j--) {
                if (nums1[i] == nums2[j]) {
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                    ans = max(ans, dp[i][j]);
                }
            }
        }

        return ans;
    }
};

// 解法二：利用后缀数组

// 解法三：二分搜索 + Rolling Hash
// 给定一个素数p
// hash(S) = \sum p^i * S[i] (i = [0..n-1])
// hash(S[1:] + x) = hash(S) - S(0) / p + p^n-1x
