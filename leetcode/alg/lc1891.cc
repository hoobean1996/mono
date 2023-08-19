// leetcode 1891
// Cutting ribbons

// 剪丝带
// 最简单的思维就是搜索，我们从丝带的最大值开始搜索，对于每个长度都进行check，是否能够切成k段
// 那么第一个满足条件的就是答案
// 但是通过把搜索问题变成二分判断的问题
// 我们就能每次排除掉1/2的备选答案，从而加速
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool check(vector<int>& ribbons, int len, int k) {
      int cnt = 0;
      for(const auto r: ribbons) {
        cnt += r / len;
        if (cnt >= k) return true;
      }
      return false;
    }

    int maxLength(vector<int>& ribbons, int k) {
        
      int l = 1;
      int r = 1e5;
      int ans = 0;

      while(l <= r) {
        int mid = l + (r - l) / 2;
        
        if (check(ribbons, mid, k)){
            l = mid + 1;
            ans = mid;
        }
        else r = mid - 1;
      }
      return ans;
    }
};