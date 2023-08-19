// leetcode 273
// Integer to English Words

// Integer to English Words
// 给定一个整数，我们需要把它转换为英语单词表达

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> to19 {
            "One",
            "Two",
            "Three",
            "Four",
            "Five",
            "Six",
            "Seven",
            "Eight",
            "Nine",
            "Ten",
            "Eleven",
            "Twelve",
            "Thirteen",
            "Fourteen",
            "Fifteen",
            "Sixteen",
            "Seventeen",
            "Eighteen",
            "Nineteen"
        };
        
        vector<string> tens {
            "Twenty",
            "Thirty", 
            "Forty", 
            "Fifty",
            "Sixty",
            "Seventy",
            "Eighty",
            "Ninety"
        };
    
    vector<string> tmb {
        "Thousand",
        "Million",
        "Billion"
    };   
    
    vector<string> helper(int num) {
        if (num == 0) return {};
        
        if (num < 20) return {to19[num-1]};
        
        if (num < 100) {
            vector<string> ans {tens[(num / 10)-2]};
            vector<string> left = helper(num % 10);
            ans.insert(ans.end(), left.begin(), left.end());
            return ans;
        }
        
        if (num < 1000) {
        vector<string> ans { to19[num / 100 - 1], "Hundred"};
            vector<string> left = helper(num % 100);
            ans.insert(ans.end(), left.begin(), left.end());
            return ans;
        }
        
        for(int i=1; i<=3; i++) {
            // thousand, million, billion 
            long long val = pow(1000, i+1);
            
            long long rval = pow(1000, i);
            
            if (num < val) {
                vector<string> ans;
                vector<string> left1 = helper(num / rval);
                vector<string> left2 = helper(num % rval);
                ans.insert(ans.end(), left1.begin(), left1.end());
                
                ans.push_back(tmb[i-1]);
                
                ans.insert(ans.end(), left2.begin(), left2.end());
                return ans;
            }
        }
        
        return {};
    }
    
    string numberToWords(int num) {
        if (num == 0) return "Zero";
    
        vector<string> ans = helper(num);
        
        string sans;
        
        for(int i=0; i<ans.size() - 1; i++) {
            sans += ans[i] + " ";
        }
        sans += ans.back();
        
        return sans;
    }
};