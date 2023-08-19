// leetcode 953
// Verfiying an Alien Dictionary

// 在一种外星语言中，他们还是使用英语单词，但是顺序和人类的顺序不同。
// 给定一个字典顺序和一组单词，我们想知道这组单词是否满足外星人词典的顺序。


// 验证外星人词典
// 将外星人词典与a..z 建立一对一的映射
// 然后将words中的单词根据这个映射转换为最终的单词
// 然后一趟比较遍历两个单词的大小关系

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        // 首先利用一个map，把外星人字典映射成人类的顺序
        // 由于外星人用的字母和人类的字母是一一对应的
        // 所以可以遍历构造该映射
        unordered_map<char, char> m;
        for(int i=0; i<order.size(); i++) m[order[i]] = (char)(i + 'a');
        
        // 在遍历整个单词数组
        for(int i=0; i<words.size(); i++) {
            // 处理每个单词，把每个单词的顺序替换成人类的顺序
            // 相当于全部转换为人类的顺序
            for(int j=0; j<words[i].length(); j++) {
                words[i][j] = m[words[i][j]];
            }
            // 替换完成以后，我们比较这个单词和上一个单词的大小关系即可
            // 然后和上一个单词比较大小
            // s.compare(t) < 0 => 是指 s < t
            if (i > 0 && words[i].compare(words[i-1]) < 0) return false;
        }
                
        return true;
    }
};