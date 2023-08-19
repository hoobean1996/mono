// leetcode 71
// Simplify Path 


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // split 函数，按照 / 划分成字符串数组
    vector<string> split(string path) {
        vector<string> ans;
        
        int lastIndex = 0;
        int index;
        
        while((index = path.find("/", lastIndex)) != string::npos) {
            ans.push_back(path.substr(lastIndex, index - lastIndex));
            lastIndex = index + 1;
        }
        if (lastIndex != path.length()) {
            ans.push_back(path.substr(lastIndex, path.length() - lastIndex));
        }
        return ans;
    }
    

    string simplifyPath(string path) {
        stack<string> sk;
        vector<string> comps = split(path);
        
        // 依次放入到栈中，如果是 . 或者 空则可忽略
        // /a/.//
        // 如果是 .. 则需要弹出上一级（如果存在)
        // 否则的话，直接放入到栈中
        for(const string s: comps) {
            if ((s == ".") || s == "") continue;
            else if (s == "..") {
                if (!sk.empty()) sk.pop();
            }
            else sk.push(s);
        }

        
        vector<string> ans;
        
        while(!sk.empty()) {
            ans.push_back(sk.top()); sk.pop();
            ans.push_back("/");
        }
        
        reverse(ans.begin(), ans.end());
        
        string ansstr;
        for(const string s: ans) ansstr += s;
       
        return ansstr.length() > 0 ? ansstr : "/";
    }
};