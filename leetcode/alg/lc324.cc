// leetcode 324
// wiggle sort ii

// 给定一个数组，希望进行Wiggle排序
// Wiggle排序的结果是nums[0] < nums[1] > nums[2] < nums[3] ...
// 基本思路是先进行排序，得到一个基本递增的数组
// 然后我们考虑先填充奇数位置的数
// 在填充偶数位置的数
// 对于奇数位置的数都是比两边的数小的，所以我们从前半部分选
// 对于偶数位置的数都是比两遍的数大的，所以我们从后半部分选
// 考虑到有重复的元素，所以我们倒序选即可

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return;
        
        // 首先把数组进行排序，可以得到一个递增的数组
        // [left] [right]
        // 由于奇数位置的元素都是较小的元素，由于可能会重复，所以倒序放置可以避免重复
        // 所以我们从[left]部分倒序开始放置即可
        sort(nums.begin(), nums.end());

        // 如果一共有偶数个元素， 0 1 2 3
        // 前一半就是 0 .. 1 (n/2 - 1)
        // 否则的话 就是 n/2
        int p1 = (n % 2 == 0 ? n / 2 - 1 : n / 2);
        
        int p2 = n - 1;
            
        vector<int> ans(n, 0);
       
        // j是开始放置的位置
        int j = 0;
        for(int i=p1; i>=0; i--) ans[j] = nums[i], j+=2;
        
        j = 1;
        for(int i=p2; i>p1; i--) ans[j] = nums[i], j+=2;

        for(int i=0; i<nums.size(); i++) nums[i] = ans[i];
    }
};