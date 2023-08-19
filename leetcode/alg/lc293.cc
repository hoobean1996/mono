// leetcode 293
// 翻转游戏
// 就是直接一个循环遍历currentState即可
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> generatePossibleNextMoves(string currentState) {
        vector<string> ans;
        for(int i=0; i<currentState.length()-1; i++) {
            if (currentState[i] == currentState[i+1]) {
                string t = currentState;
                if (t[i] == '+') {
                    t[i] = '-';
                    t[i+1] = '-';
                    ans.push_back(t);
                }
            }
        }
        
        return ans;
    }
};