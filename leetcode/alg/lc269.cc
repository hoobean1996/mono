// leetcode 269
// Alien Dictionary 

// 外星人词典
// 这道题是说字母不按照abcd来排序了
// 按照某种奇怪的方式来排序，我们有一组有序的词
// 需要找到这个排序方式
// 这道题把字符顺序转换为DAG就很清楚了

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string alienOrder(vector<string>& words) {
        
        // orders 相当于DAG中的边
        set<pair<char, char>> orders;
        
        // chars 所有的字母
        unordered_set<char> chars;
        for(const auto w: words) chars.insert(w.begin(), w.end());
        
        // 用于统计入度
        vector<int> in(256);
        
        for(int i=0; i<words.size()-1; i++) {
            // 较短的字符串
            int mi = min(words[i].size(), words[i+1].size());
            int j = 0;
            for(; j<mi; j++) {
                // 如果两个字符串的相同位置的字符不相同，证明存在一个顺序
                // word[i][j] -> word[i+1][j]
                if (words[i][j] != words[i+1][j]) {
                    orders.insert({words[i][j], words[i+1][j]});
                    break;
                }
            }
            if (j == mi && words[i].size() > words[i+1].size()) return "";
        }

        // 统计入度
        for(const auto &o: orders) ++in[o.second];

        string res;

        queue<char> q;
        // 将入度为0的节点放入
        for(const auto c: chars) {
            if (in[c] == 0) {
                q.push(c);
                res += c;
            }
        }

        while(!q.empty()) {
            char t = q.front(); q.pop();
            for(const auto& o: orders) {
                if (o.first == t) {
                    --in[o.second];
                    if (in[o.second] == 0)  {
                        q.push(o.second);
                        res += o.second;
                    }
                }
            }
        }
        return res.size()  == chars.size() ? res : "";
    }
};