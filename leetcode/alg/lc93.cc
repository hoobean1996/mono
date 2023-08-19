// leetcode 93
// Restore IP Addresses


// 给一串连续的数字，可能是合法的IP地址
// 我们需要还原它为可能的IP地址
// IP地址的格式 xxx.xxx.xxx.xxx 其中xxx in [1, 255]
class Solution {
public:
    vector<string> _ans;
    
    void backtrack(int cur, string s, vector<string>& path) {
        // 终止条件
        if (cur == s.length() && path.size() == 4) {
            // Format
            string ip = path[0];
            for(int i=1; i<path.size(); i++) ip += "." + path[i];
            _ans.push_back(ip);
            return;
        }
        
        // 因为最多三位
        // cur .. i 构成了当前的IP
        // 所以backtrack(i+1, s, path);
        for(int i=cur; i<cur+3; i++) {
            if (i >= s.length()) return;
            
            // 0xx 不合法
            if (s[cur] == '0' && i > cur) return;
            
            string _num = s.substr(cur, i - cur + 1);
            int num = stoi(_num);
            
            if (num > 255) continue;
            
            path.push_back(_num);
            
            backtrack(i + 1, s, path);
            
            path.pop_back();
        }
        
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> path;
        
        backtrack(0, s, path);
        
        return _ans;
    }
};