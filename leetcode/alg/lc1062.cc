// leetcode 1062
// Longest Repeating Substring
// 最长重复字串


// 给定一个字符串，我们希望找到在这个字符串中重复出现的字串中，
// 最长的字符串的长度是多少
// 比如abab -> 那么最长的重复的字串是ab, 长度为2

// 第一种解法是利用Rolling Hash + 二分搜索，复杂度是O(nlogn)
// 第二种解法是利用后缀数组，最长重复字串的长度等于height数组的最大值
#include <bits/stdc++.h>

using namespace std;

// 利用后缀数组实现
int n;
int k;
vector<int> sa;
vector<int> rk;
vector<int> tmp;
vector<int> height; 

bool cmp(int i, int j) {
    if (rk[i] != rk[j]) return rk[i] < rk[j];
    int ri = i + k <= n? rk[i+k] : -1;
    int rj = j + k <= n? rk[j+k] : -1;
    return ri < rj;
}

class Solution {
public:
    int longestRepeatingSubstring(string s) {
        n = s.length();
        if (n == 0) return 0;
        
        sa = vector<int>(n+1, 0);
        rk = vector<int>(n+1, 0);
        tmp = vector<int>(n+1, 0);
        height = vector<int>(n+1, 0);
        
        
        for(int i=0; i<=n; i++) {
            rk[i] = s[i] - 'a';
            sa[i] = i;
        }
        
        for(k=1; k<=n; k*=2) {
            sort(sa.begin(), sa.end(), cmp);
            tmp[sa[0]] = 0;
            for(int i=0; i<n; i++) tmp[sa[i+1]] = tmp[sa[i]] + (cmp(sa[i], sa[i+1]) ? 1 : 0);
            for(int i=0; i<n; i++) rk[i] = tmp[i];
        }
        
        int ans = 0;
        int p = 0;
        for(int i=0; i<n; i++) {
            if (p) p--;
            int j = sa[rk[i] - 1];
            while(i+p < n && j+p < n && s[i+p] == s[j+p]) p++;
            height[rk[i]] = p;
            ans = max(ans, height[rk[i]]);
        }
        return ans;
    }
};