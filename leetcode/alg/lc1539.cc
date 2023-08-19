// leetcode 1539
// Kth Missing Positive Number 

// 给定一个正数数组，严格递增。
// 找到在第k个消失的正数
// 比如arr = [2,3,4,7,11], k = 5
// 为了形成连续的区间，我们缺失的数字是 [1,5,6,8,9,10,12,13,...]
// 所以第5个缺失的数字是 9
// 考虑这个缺失的数是x，[1..x]有m个数
// 分别为 [0], [1], .., [m-1]
// 那么对于小于[m]的数来说，缺失的数目为 A[m] - 1 - m  (一共有的数 - m个已经存在的)
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        
        int l = 0;
        int r = n - 1;
        
        while(l < r) {
            int mid = l + (r - l) / 2;
            
            // 二分法，考虑当前的mid位置这个数，对于他来说，缺失的数
            // 其实就是arr[mid] - 1 （总数)
            // mid 刚好是下标 从而代表当前mid的左侧有多少个数
            if (arr[mid] - mid - 1 < k) l = mid + 1;
            else r = mid;
        }
        
        // 最后的时候
        // l = r + 1
        // 考虑当前对于r位置的数来说，在 1..arr[r]这个区间缺失的数就是
        // total = arr[r] - right - 1 
        // 那么第k个消失的数就是
        // arr[r] + k -  (arr[r] - r - 1) 
        // = k + r + 1 
        // 也就是 l + k的情况
        return l + k;
    }
};