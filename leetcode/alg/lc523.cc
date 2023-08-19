// leetcode 523
// Continuous Subarray Sum

// 连续的子数组和为target的倍数
// 至少两个元素
#include <bits/stdc++.h>

using namespace std;     

class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {   
        // 如果少于两个元素，肯定是false
        if (nums.size() < 2) return false;

        unordered_map<int, int> m;
        int sum = 0;

        // 由于0始终是k的倍数
        // 所以如果存在连续的两个0 0 ，那肯定是true的
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1] && nums[i] == 0) return true;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            // 如果只有一个0， 0是不会影响和的
            if (nums[i] == 0) continue;
            // 求解前缀和
            sum += nums[i];
            // 如果sum % k == 0 && i >= 1
            // 保证个数至少为2, sum % k == 0
            // sum % k != 0, 假设 sum = nk + p
            // 如果还有一个前缀和 sum' = n'k + p
            // 做差的话，就能得到一个区间sum - sum' = (n - n')k, 肯定是k的倍数
            // 同时要保证长度至少为2
            if (sum % k == 0 && i >= 1 || m.count(sum % k) && (i - m[sum % k]) >= 2) return true;

            m[sum % k] = i;
        }

        return false;
    }
};