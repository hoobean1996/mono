// leetcode 605
// Can Place Flowers

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int ans = 0;
        
        for(int i=0; i<flowerbed.size(); i++) {
            // 如果当前位置为1，跳过
            if(flowerbed[i] == 1) continue;
            
            // 如果当前位置的前一个位置为1，跳过
            if (i-1 >= 0 && flowerbed[i-1] == 1) continue;
            // 如果当前位置的后一个位置为1，跳过
            if (i+1 < flowerbed.size() && flowerbed[i+1] == 1) continue;
            
            flowerbed[i] = 1;
            ans ++;
        }
        
        return ans >= n;
    }
};