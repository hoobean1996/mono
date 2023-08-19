// leetcode 556
// Next Greater Element III
// 给定一个整数n，我们想要找到它的下一个刚好比他大的数，并且这个数和他包含一样的数字
// 把整数转换为字符串，然后利用next permutate的算法即可

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
        if (n < 10) return -1;
        
        string s = to_string(n);
        
        // 找到第一个升序的位置
        int i = s.length() - 2;
        while(i >= 0 && s[i+1] <= s[i]) i--;
        if (i < 0) return -1;

        // 从末尾开始找到第一个大于i的位置
        int j = s.length() - 1;
        while(j >= 0 && s[j] <= s[i]) j--;
        
        // 交换
        swap(s[i], s[j]);
        
        // 将后半部分reverse
        reverse(s.begin() + i + 1, s.end());
        
        return stoi(s);
    }
};