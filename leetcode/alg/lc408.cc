// leetcode 408
// Valid Word Abbreation

// 判断一个长字符串和一个短字符串是否满足缩写关系
// 缩写的规则是可以用长度替换到字符串中的任何子串
// substitution
// 12
// s10n
// sub4u4
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int j = 0;

        int i = 0;
        // 双指针指向两个字符串
        // 如果是字母的话，必须相同
        // 如果是数字的话，先把多位数字计算出来，然后移动原字符串的指针位置
        // 最后两个指针都应该在末尾就可以
        while (i < abbr.length() && j < word.length()) {
            // 双指针，分别指向两个字符串
            // 如果缩写的位置是一个字符，那么必须和word相同，否则false
            if (isalpha(abbr[i])) {
                if (abbr[i] != word[j]) return false;
                else {
                    i++;
                    j++;
                }
            }
            // 如果缩写的位置是一个数字
            // 尝试计算数字并移动指针
            else if (isdigit(abbr[i])) {
                int n = 0;
                // 如果是leading 0的话，必须是字符0，不能当作数字
                if (n == 0 && (abbr[i] - '0' == 0)) {
                    if (abbr[i] != word[j]) return false;
                    else {
                        i++;
                        j++;
                    }
                }
                else {
                    while (isdigit(abbr[i])) {
                        n = 10 * n + abbr[i] - '0';
                        i++;
                    }
                    j += n;
                }
            }
        }

        if (i == abbr.length() && j == word.length()) return true;
        return false;
    }
};