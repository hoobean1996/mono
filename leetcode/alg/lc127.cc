// leetcode 127
// Word Ladder

// 成语接龙 I
// 给定一个开始成语和结束成语，和一个可用的成语词典。
// 我们想知道从开始的成语变化到结束的成语的最小次数是多少

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (wordList.size() == 0) return 0;
        
        int n = wordList.size();
        
        // 利用BFS求解最短路
        vector<int> d;
        d.assign(n+1, -1);
       
    
        wordList.push_back(beginWord);
        
        queue<int> q;
        q.push(n);
        d[n] = 1;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(int i=0; i<n; i++) {
                if (d[i] == -1) {
                    if (_check(wordList[u], wordList[i])) {
                        if (wordList[i] == endWord) return d[u] + 1;
                        d[i] = d[u] + 1;
                        q.push(i);
                    }
                }
            }
        }
        
        return 0;
    }
    

    bool _check(string& s1, string& s2) {
        int cnt = 0;
        for(int i=0; i< (int)s1.size(); i++) {
            if (s1[i] != s2[i]) cnt++;
        }
        return cnt == 1;
    }
};