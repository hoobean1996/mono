// leetcode 628
// Maximum ans of Three Numbers
// 选择三个数使得乘积最大

// 选取k个数，使得乘积最大
/*
if n== k 所有的数字都要被选择，那么答案就是n个数字相乘
if n<k 不合法
if n>k 
if k%2 == 0
    如果负数为偶数个，负负得正，答案必定是正数
    如果负数为奇数个，则总有落单的负数，那我们只选择偶数个最大的负数，答案必定是正数
if k%2 == 1
    如果所有数字都为负数，那么答案肯定就是负数
    如果起码有一个正数，那我们把单独的整数拿出来，k - -,此时k转换为了偶数，回归到前面的式子进行解决


我们可以发现，除了k是 奇数 且 所有数字都为负数 的情况是负数，其他情况下都可以转换为正数
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumans(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();        
        
        // 如果全是正数/全是负数的话，直接返回最大的三个乘积即可
        if (nums[0] * nums[n-1] >= 0) {
            return nums[n-1] * nums[n-2] * nums[n-3];
        }
        
        // 双指针来挑选，count是我们需要的个数
        int l = 0, r = n-1;
        int ans = 1;
        int count = 3;
        
        while(count > 0) {
            // 如果count是奇数，那么我们应该选右侧的
            // 因为右侧的那个数是最大的
            if(count % 2 == 1)  {
                ans *= nums[r--];
                count --;
            }
            // 如果count是偶数的话，那么我们就要挑选出一对偶数
            else {
                if(nums[r]*nums[r-1] > nums[l]*nums[l+1]) {
                    ans *= nums[r] * nums[r-1];
                    r -= 2;
                }
                else {
                    ans *= nums[l] * nums[l+1];
                    l += 2;
                }
                count -= 2;
            }
        }
        
        return ans;
    }
};