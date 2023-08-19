// leetcode 38
// Count and Say

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string next(string s) {
        if (s.length() == 1) return "1" + s;
        
        char first = s[0];
        int count = 1;
        
        string ans;
        
        for(int i=1; i<s.length(); i++) {
            if (s[i] == first) {
                count ++;
                continue;
            } else{
                ans += to_string(count);
                ans += first;
                
                first = s[i];
                count = 1;
            }
        }
        
        if (count > 0) {
            ans += to_string(count);
            ans += first;
        }
        
        return ans;
    }
    
    string countAndSay(int n) {
        
        string s = "1";
        if (n == 1) return s;
        
        for(int i=1; i<n; i++) s = next(s);
        
        return s;
    }
};