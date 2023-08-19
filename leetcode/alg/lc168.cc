// leetcode 168
// Excel Sheet Column Title

// A -> 1
// B -> 2
// C -> 3
// Z -> 25
// 每次把当前的值 % 26以后得到当前的值，然后除26
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string convertToTitle(int col) {
        // 注意到是从1开始的
        // 所以 A -> 1
        // 所以col -- 以后在取模就可以了
        string ans;
        while(col--){
            ans += 'A'+(col % 26);
            col /= 26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};