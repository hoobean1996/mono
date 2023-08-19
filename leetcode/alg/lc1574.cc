// leetcode 1574
// Shortest Subarray to be Removed to Make Array Sorted

// 给定一个无序数组，我们可以删除它的某一部分子数组，
// 我们希望知道，如果让剩下的数组成为有序数组，我们可以删除的最短的数组的长度是多少

// 因为我们必须删除的是连续的子数组(可以为空)
// 首先考虑两段分别有序的子数组
// 分别从左往右扫描 和 从右往左扫描，得到左右两侧有序的数组的长度。
// 然后由于我们可以删除中间的子数组，所以我们可以利用两路归并算一个最大值即可

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();

        // 从左往右扫描得到当前的左侧的有序数组的长度
        int l = 1;
        while(l < n and arr[l] >= arr[l-1]) l ++;
        if (l == n) return 0;
        
        l -= 1;
        
        // 从右往左扫描得到当前的右侧的有序数组的长度
        int r = n - 2;
        while(r >= 0 and arr[r] <= arr[r+1]) r --;
        
        r += 1;
        int ans = max(l + 1, n - r);
        
        //  归并两个有序数组为一个有序数组
        // 同时计算它的长度
        // 用总长度减去归并以后的有序数组的长度，就得到了我们需要删去的长度
        int i = 0;
        int j = r;
        
        while(i <= l and j < n) {
            if (arr[i] <= arr[j]) {
                ans = max(ans, i + 1 + n - j);
                i ++;
            }
            else j ++;
        }
        
        return n - ans;
    }
};