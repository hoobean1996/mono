// leetcode 264
// Ugly Number II

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly {1};
        
        // 三个指针
        int i = 0;
        int j = 0;
        int k = 0;
        
        for(int idx=1; idx<n; idx++) {
            // 每次从三个指针里面选取最小的
            int newUgly = min(ugly[i]*2, min(ugly[j]*3, ugly[k]*5));
            ugly.push_back(newUgly);
            // 更新对应的值
            if (ugly.back() == ugly[i]*2) i++;
            if (ugly.back() == ugly[j]*3) j++;
            if (ugly.back() == ugly[k]*5) k++;
        }
        
        return ugly.back();
    }
};