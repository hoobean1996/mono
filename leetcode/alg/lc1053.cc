// leetcode 1053
// Previous Permutation With One Swap
// 前一个Permutation
// 是下一个Permutation的对称问题
// 由于完全升序的数组是没有前一个permutation的
// 所以我们要尝试找到一个降序的位置
// 从右到左遍历，如果没有找到降序的位置 i < 0 直接返回
// 如果找到了， 那么位置就是 i i+1 and A[i] > A[i+1]
// 同时我们要在i+1 .. end的范围内，找到 < A[i] and > A[i+1]的最大值
// 然后把i .. k进行交换即可
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int i = arr.size()-2;
        while(i >= 0 and arr[i] <= arr[i+1]) i--;
        if(i < 0) return arr;
        
        int k = i+1;
        for(int j = i+1; j < arr.size(); j++) {
            if(arr[i] > arr[j] and arr[j] > arr[k]) k = j;
        }
        
        swap(arr[i],arr[k]);
        
        return arr;
    }
};