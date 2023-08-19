// leetcode 288
// Unique Word Abbreviation

// 如果一个单词只有两个字母，那么缩写就是他自己
// 如果一个单词超过两个字母，那么保留首尾字母，并用数字代表中间的字母个数
// 给定一个词典，我们想知道它对应的缩写是否是唯一的
// 换句话说，给定一个缩写，能否对应词典中的多个单词
// 基本思路就是第一步，生成缩写词典
// 然后比较个数
#include <bits/stdc++.h>

using namespace std;

class ValidWordAbbr {
public:
    unordered_map<string, unordered_set<string>> m;
    
    ValidWordAbbr(vector<string>& dictionary) {
        for(int i=0; i<dictionary.size(); i++) {
            string w = dictionary[i];
            
            string k = w;
            
            if (w.length() > 2) k = w[0] + to_string(w.length() - 2) + w[w.length() - 1];
            
            m[k].insert(w);
        }
    }
    
    bool isUnique(string word) {
        string k = word;
        
        if (word.length() > 2) k = word[0] + to_string(word.size() - 2) + word[word.length() - 1];
        return m[k].count(word) == m[k].size();
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */