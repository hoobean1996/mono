// leetcode 824
// Goat Latin

// 给定一些句子，这些句子包含多个单词
// 我们想要按照以下规则来修改这个句子
// 1. 如果是由 aeiou的元音开头的，append ma在单词末尾
// 2. 如果从constants开头的，删去第一个字符，并添加到单词末尾，然后添加ma到末尾
// 3. 第几个单词，就在第几个单词的末尾添加多少个a
// 直接按照规则模拟即可
// 首先实现一个split函数，将句子划分为多个单词，然后对于每个单词都进行模拟即可
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string aeiou = "aeiouAEIOU";

    string convert(string sub, int count) {
        // 如果是这个开头，添加ma
        if (aeiou.find(sub[0]) != string::npos) sub += "ma";
        else {
            // 其他情况
            sub = sub.substr(1) + sub[0] + "ma";
        }
        // 追加count个a
        for(int i=0; i<count; i++) sub += "a";
        return sub;
    }
    
    string toGoatLatin(string sentence) {        
        int index;
        int lastIndex = 0;
        
        string ans;
        int count = 1;
        
        while((index = sentence.find(" ", lastIndex)) != string::npos) {
            string sub = sentence.substr(lastIndex, index - lastIndex);
            lastIndex = index + 1;
            ans += convert(sub, count) + " ";
            count ++;
        }
        
        if (lastIndex != sentence.length()) {
            string sub = sentence.substr(lastIndex, sentence.length() - lastIndex);
            
            ans += convert(sub, count);
        }
        
        return ans;
    }
};