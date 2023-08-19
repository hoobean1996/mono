// leetcode 2104
// Sum of Subarray Ranges

// 所有子数组的最大值最小值的差值的和
// 对于一个数组的所有子数组，我们考虑每个子数组的最大值和最小值，能够得到一个差值
// 我们想知道的是所有子数组的差值的和是多少
// 最直观的想法是我们直接求解所有的子数组，然后找到最大值和最小值并求解
// 这样的复杂度是O(2^n * n)
// 非常高，考虑最大值和最小值的特殊性，我们试试用单调栈来解决
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // 整体的思路是我们利用单调栈，在弹出的时候，来确定栈顶元素作为可能的最值的可能的数组
    // 的情况数量，然后利用 x * (left) * right 得到所有情况的值
    
    // 问所有子数组内（最大值-最小值）的和
    // 相当于问所有子数组的最大值的和 - 所有子数组的最小值的和
    // 考虑a[i]作为子数组的最小值的情况
    // 考虑以a[i]作为结尾的情况 (i-l) 
    // 考虑以a[i]作为开始的情况 (r-l)
    long long subArrayRanges(vector<int>& nums) {
        const int n = nums.size();
        
        // function<bool(int, int)> 
        // 函数为 (int, int) -> bool 的lambda 函数
        // less<int>()
        // greater<int>()
        auto sumOf = [&](function<bool(int, int)> op) {
            long long ans = 0;
            
            stack<int> s;
            for(int i=0; i<=n; i++) {  
                // 多跑一次循环，用于把最后一个节点的情况处理干净  
                // op(nums[s.top()], nums[i]) 
                // 等价于 nums[s.top()] op nums[i]
                while(!s.empty() && (i == n || op(nums[s.top()], nums[i]))) {
                    // k 是当前栈顶元素的下标
                    long long k = s.top(); s.pop();
                    long long j = s.empty() ? -1 : s.top();
                    // 整体的布局是 [j, k, i]
                    // 那么从j .. k这一段，是以nums[k]作为尾巴的最大值的子数组数量是 k - j
                    // 那么从k .. i这一段，是以nums[k]作为开始的最大值的子数组数量是 i - k
                    ans += nums[k] * (i - k) * (k-j);
                }
                s.push(i);
            }
            return ans;
        };

        // less<int> 返回是否第一个参数小于第二个参数
        return sumOf(less<int>()) - sumOf(greater<int>());
    }
};

// C++ lambda 表达式
// [] 默认不捕获任何变量
// [=] 默认以值捕获所有变量
// [&] 默认以引用捕获所有的遍历
// [x] 仅以值捕获x
// [=, &x] 默认以值捕获，但是x用引用捕获
// [&, x] 默认以引用捕获，但是x以值捕获