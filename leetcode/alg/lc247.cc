// leetcode 247
// Strobogrammatic Number II

// 给定一个数字n
// 返回所有长度为n的中心对称数字
// 这道题是利用BFS做的

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        map<char, char> m = {
            {'0', '0'},
            {'1', '1'},
            {'6', '9'},
            {'8', '8'},
            {'9', '6'}
        };
        
        queue<string> q;
        int curLength;
        
        if (n % 2 == 0) {
            curLength = 0;
            q.push("");
        }
        else {
            curLength = 1;
            q.push("0");
            q.push("1");
            q.push("8");
        }
        
        while(curLength < n) {
            curLength += 2;
            
            for(int i=q.size()-1; i>=0; i--) {
                string number = q.front();
                q.pop();
                
                for(auto it=m.begin(); it!=m.end(); it++) {
                    if (curLength < n || it->first != '0') q.push(it->first + number + it->second);
                }
            }
        }
        
        vector<string> stroboNumbers;
        while(!q.empty()) {
            stroboNumbers.push_back(q.front()); q.pop();
        }
        
        return stroboNumbers;
    }
};