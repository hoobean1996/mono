// leetcode 
// Find Bad Version

// 是很简单的二分查找的应用

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 0;
        int r = n;
        
        while(l <= r) {
            int mid = l + (r-l) / 2;
            if (isBadVersion(mid)) r = mid - 1;
            else l = mid + 1;
        }
        
        return l;
    }
};