// leetcode 852
// Peak Index in a Mountain Array
// 我们有一个Montain Array，想找到Mountain点
//  - Mountain Array是一个数组长度至少为3
//  - Mountain点左侧元素是递增的
//  - Mountain点右侧元素是递减的
// 对于任何位置index,
// 如果a[index] < a[index+1] 那么证明index是在上升部分，所以 index和index之前的 都不可能是答案
// 如果a[index] > a[index+1] 那么证明index是在下降部分，所以index和index之后的都不可能是答案
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        // 初始化的条件为 1 和 n-1
        int l = 1;
        int r = arr.size() - 1;
        
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] < arr[mid+1]) l = mid + 1;
            else r = mid - 1;
        }
        
        return l;
    }
};