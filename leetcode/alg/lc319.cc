// leetcode 319
// Switch Bulbs

// 考虑将灯泡从 1 ... n编号
// 第一次 所有1的倍数的灯都会被操作一次
// 第二次 所有2的倍数的灯都会被操作一次
// 第i次  所有i的倍数的灯都会被操作一次

// 翻过来想，对于一个编号为i的灯，它被操作的次数其实是 i的因数，包括自己
// 1 * i, 2 * i/2 ...
// 而因子是成对出现的，如果一个灯被操作偶数次，那么就不会改变状态
// 所以问题变成了，有哪些数有奇数个因子
// 其实就是完全平方数，完全平方数只有技术个因子
// 那么对于n栈灯，操作n次，我们需要找到的是其中有多少个编号是完全平方数
// 个数为 sqrt(n)

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int bulbSwitch(int n) {
        return (int)sqrt(n);    
    }
};