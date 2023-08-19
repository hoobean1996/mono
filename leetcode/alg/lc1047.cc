// leetcode 1047
// Remove All Adjacent Duplicates in String 
// 给定一个字符串，我们需要消除两个连续的相同的字符
// 并且对消除以后对字符串反复操作，直至不能操作为止
// abbaca -> ac
// 考虑字符串ans是满足条件的字符串
// 那么我们遍历整个字符串的时候，如果ans不为空, ans的最后一个字符和当前字符是相同的，那么都需要删除
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        string ans;
        
        for(int i=0; i<s.length(); i++) {
            if (ans.size() > 0 && s[i] == ans.back()) {
                ans.pop_back();
            }
            else ans += s[i];
        }
        
        return ans;
    }
};