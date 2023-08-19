// leetcode 528
// Random Pick With Weight 

// 带权随机选择的实现
// 给定一个数组，每个元素代表一个权值
// 我们希望实现一个函数 pickIndex，这个函数能够从[0, w.length() - 1]
// 选择第i个格子的概率是 w[i] / sum(w)
// 比如 [1, 3]
// 概率分布应该是 0.25, 0.75
// 我们考虑每个格子都是由若干个小球组成的
//  1. 生成一个0-1范围内的小数 (float) rand() / RAND_MAX;
//  2. 生成一个在 target = [0, 1] * sum(w)区间的一个可能的值
//  3. 返回第一个 >= target的格子即可
#include <bits/stdc++.h> 

using namespace std;

class Solution {
public:
    vector<int> _prefixSum;
    
    Solution(vector<int>& w) {
        for(const auto x: w) {
            // 考虑把所有的元素都想成多个1的组合体
            // 然后我们直接求出前缀和
            _prefixSum.push_back(x + (_prefixSum.empty() ? 0 : _prefixSum.back()));
        }
    }
    
    int pickIndex() {
        // 生成一个 0 - 1范围内的小数
        float r = (float) rand() / RAND_MAX;
        
        // (0, 1) * 最大的值， 得到该区间内的所有可能的情况
        float target = r * _prefixSum.back();
                    
        // 范围第一个 >= target的值
        return lower_bound(begin(_prefixSum), end(_prefixSum), target) - begin(_prefixSum);
    }
};