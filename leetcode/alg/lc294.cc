// leetcode 294
// Flip Game II
// 翻转游戏 2

// 枚举 + 搜索所有的情况
// 首先对于当前的state, 如果没有可以翻转的，返回false
// 如果有翻转的，我们继续搜索翻转以后的状态

// 从初始状态开始，穷举所有连续加号进行翻转，如果存在某种翻转使得子状态必败，那么该状态必胜；
// 否则该状态必败。
// helper 返回当前的状态是否必然失败

// 这道题和二分图很类似
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
// 采用记忆化搜索
    bool canWin(string currentState) {
        unordered_map<string, bool> memo;
        return helper(currentState, memo);
    }
    
    // 对于当前状态state来说，
    // 如果没有可以翻转的 -> 证明当前的状态必然失败 返回false
    // 如果反转的某个状态是必败的 -> 证明当前的状态必然可以成功 返回true
    bool helper(const string& state, unordered_map<string, bool>& memo) {
        if (memo.find(state) != memo.end()) return memo[state];

        for(int i=0; i<state.length()-1; i++) {
            if (state[i] == state[i+1] && state[i] == '+') {
                string s = state;
                s[i] = '-';
                s[i+1] = '-';

                if (!helper(s, memo)) {
                    memo[state] = true;
                    return true;
                }
            }
        }

        memo[state] = false;
        return false;
    }
};