// leetcode 1011
// Capacity to Ship Packages Within Days

// 我们有一些包裹，我们希望在给定的时间内运输到目的地。
// 但是我们有一个capacity，如果超过了capacity的情况下，肯定是需要等下一次运输的
// Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
// 比如这种情况下，capacity是15
// 如果capacity < 15 是无法在days=5完成运输的
// capacity > 15，是能够完成运输的，但是capacity不是最小值

// 利用二分搜索capacity即可
// 注意最后的答案应该是最大的元素和l中取最大值
// 如果l < max，那么就有一个package是无法convey的
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // check 函数检查当前的capacity能否在给定的时间内运输完
    bool check(vector<int>& weights, int capacity, int days) {
        int sum = weights[0];
        int group = 1;
        for(int i=1; i<weights.size(); i++) {
            // 如果加上这一天的，超过了capacity，那么肯定只能是下一天了
            if (sum + weights[i] > capacity) {
                group ++;
                sum = weights[i];
            }
            else sum += weights[i];
        }
        return group <= days;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        // 考虑二分法，我们至少要运输一个每天
        // 最大值是所有包裹的和，假设我们有一个非常大的运输机，那么一天就能运输完成
        // 对于每个中点mid，我们都尝试去check是否能满足在给定的时间内运输完成
        int l = 1;
        
        int r = accumulate(weights.begin(), weights.end(), 0);
        int maxPackage = *max_element(weights.begin(), weights.end());        
        
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if (check(weights, mid, days)) r = mid - 1;
            else l = mid + 1;
        }

        // 需要考虑的是maxPackage，假设有一个超大的包裹，其他都是很小的，那么至少也需要maxPackage
        // 才能运输完它
        return max(maxPackage, l);
    }
};