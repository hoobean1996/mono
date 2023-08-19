// leetcode 321
// Create Maximum Number

// 从两个数组中，选取k个数构成一个最大的数值。

// 1. 给定一个无序的子数组，从中找出k个数构成一个整数，k个数之间相对位置不变，使得新构成的数最大
// 2. 给定两个数组，从中交替选数字出来，从前往后选，构成一个新数组，使得这个数组最大

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    // fn 用于实现在一个数组中，选取k个数，构成一个单调递减栈
    vector<int> fn(vector<int> &arr, int k)
    {
        vector<int> ans(k);
        for (int i = 0, n = 0; i < arr.size(); i++)
        {
            while (n && ans[n - 1] < arr[i] && n + arr.size() - i > k)
                n--;
            if (n < k)
                ans[n++] = arr[i];
        }
        return ans;
    }

    bool cmp(vector<int> &val1, int i1, vector<int> &val2, int i2)
    {
        for (; i1 < val1.size() && i2 < val2.size(); i1++, i2++)
        {
            if (val1[i1] > val2[i2])
                return true;
            if (val1[i1] < val2[i2])
                return false;
        }

        return i2 == val2.size();
    }

    vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k)
    {
        vector<int> ans(k);

        // 一共要k个数，我们可以枚举所有的情况
        // 从第一个数组中选i个数构成vals1
        // 从第二个数组中选k-i个数构成vals2
        // 然后我们需要将vals1，vals2合并成一个最大数组
        // 最终的结果就是在这些最大数组中选择

        for (int i = 0; i <= k; i++)
        {
            if (i <= nums1.size() && k - i <= nums2.size())
            {
                vector<int> val1 = fn(nums1, i);
                vector<int> val2 = fn(nums2, k - i);
                vector<int> cand;
                for (int i1 = 0, i2 = 0; i1 < val1.size() || i2 < val2.size();)
                {
                    if (cmp(val1, i1, val2, i2))
                        cand.push_back(val1[i1++]);
                    else
                        cand.push_back(val2[i2++]);
                }
                ans = max(ans, cand);
            }
        }

        return ans;
    }
};