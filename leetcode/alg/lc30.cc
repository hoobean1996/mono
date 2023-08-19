// leetcode 30
// Substring with Concatention of All words.

#include <bits/stdc++.h>

using namespace std;

// 需要小心Java的substring方法和C++的substr方法的参赛意义不同
// 给定一组长度相同的字符串，
// 然后在给定的字符串中找到所有的子串的位置，这些子串是由上面的字符串拼接组成
class Solution {
public:
    int n;
    int wordLength;
    int substringSize;
    int k;
    unordered_map<string, int> wordCount;
    
    vector<int> findSubstring(string s, vector<string>& words) {
        n = s.length();
        // 由于是由words里面的字符串组成的长字符串
        // 所以我们可以求得子串应有的长度
        k = words.size();
        // 单个单词的长度
        wordLength = words[0].length();
        // 整个子串的长度
        substringSize = wordLength * k;
        
        // 统计words中每个字符串出现的次数，
        // 可以重复使用
        for(const string word: words) wordCount[word] ++;
        
        vector<int> ans;
        
        for(int i=0; i<wordLength; i++) {
            // SlidingWindow 尝试找到从当前位置i开始是否有合法的字符串
            slidingWindow(i, s, ans);
        }
        
        return ans;
    }
    
    // l 代表当前滑动窗口的左边界
    // r 代表当前滑动窗口的右边界
    void slidingWindow(int l, string s, vector<int>& ans) {
        // 当前滑动窗口已经找到的单词
        unordered_map<string, int> wordsFound;
        
        int wordsUsed = 0;

        bool excessWord = false;
        
        // 以l为左边界，r为右边界的子串
        // 每次长度 += wordLength, 因为所有的长度都是一样的长度
        // 枚举所有可能的字串
        for(int r=l; r<=n-wordLength; r+=wordLength) {
            // 以r为开始的子串
            string sub = s.substr(r, wordLength);
            
            // 如果wordCount不包含sub，那么肯定是无法匹配的
            // 重置所有状态并移动l
            if (wordCount.count(sub) == 0) {
                wordsFound.clear();
                wordsUsed = 0;
                excessWord = false;
                l = r + wordLength;
            }
            // 如果wordCount包含sub
            else {
                // 移动l的情况
                while(r - l >= substringSize || excessWord) {
                    // 以l为开始的子串
                    string leftmostWord = s.substr(l, wordLength);
                    // 把区间缩小
                    l += wordLength;
                    wordsFound[leftmostWord]--;
                    
                    if (wordsFound[leftmostWord] >= wordCount[leftmostWord]) excessWord = false;
                    else wordsUsed --;
                }
                // 统计当前的窗口信息
                // 但是很有可能由于引入了当前的r，导致该窗口不满足条件
                // 1. 区间过大
                // 2. 单词频次过多
                // 我们都需要移动l使得该区间变小，从而从新满足条件
                wordsFound[sub] ++;
                if (wordsFound[sub] <= wordCount[sub]) wordsUsed ++;
                else excessWord = true;
                if (wordsUsed == k && !excessWord) ans.push_back(l);
            }
        }
    }
};