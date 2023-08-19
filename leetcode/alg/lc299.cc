// leetcode 299
// Bulls and Cows

// Bulls and Cows 是一个游戏
// 你写下一个秘密数字，然后让你的朋友来猜猜，当你的朋友猜的时候，我们基于以下规则来给出反馈
// 1. The number of bulls. 就是朋友猜的数字中正确的那些数位的个数
// 2. The number of cows. 就是朋友猜的数字中数字正确，但是位置不对的个数
// 我们要做的就是对于朋友的猜测，我们要给出正确hint
#include <bits/stdc++.h>

using namespace std;

string getHint(string secret, string guess) {
    // bulls 是相同位置相同字符的个数
    // cows 是字符相同但是位置不同的个数
    int bulls = 0;
    int cows = 0;

    unordered_map<char, int> h;

    int n = guess.length();

    // 循环遍历整个字符串，然后依次对比每个字符，
    // 如果字符相同，就是bulls++
    // 如果字符不同，由于我们要对比字符相同但是位置不同，
    // 所以我们利用一个unordered_map来计数，
    // 对于每一个guess 的字符 我们都去--
    // 对于每一个secret的字符 我们都去++, 如果他们有相同的字符的话（但是位置不同）
    // 那么就可能 h[s] ++ 但是被其他位置的 h[g] -- 给抵消掉了
    for(int i=0; i<n; i++) {
        char s = secret[i];
        char g = guess[i];
        // 如果两个字符相同的话，很简单 bulls ++
        if (s == g) bulls ++;
        // 但是如果不同的话，如果处理呢
        else {
            // 既然secret的字符是 ++，如果遇到了 <0的话
            // 证明存在guess和这个字符对应，同时比它还多
            if (h[s] < 0) cows ++;
            if (h[g] > 0) cows ++; 
            
            // 考虑让secret的字符 ++ 表示该字符多了一个secret
            h[s] ++;
            // 考虑让guess的字符 -- 表示该字符多了一个guess
            h[g] --;
        }
    }

    return to_string(bulls) + "A" + to_string(cows) + "B";
}