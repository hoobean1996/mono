// leetcode 256
// Paint Houses

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int red = 0;
        int blue = 0;
        int green = 0;

        // 考虑把当前的房子涂成不同的颜色的情况下，需要的cost
        for(int i=0; i<costs.size(); i++) {
            int preRed = red;
            int preBlue = blue;
            int preGreen = green;

            red = costs[i][0] + min(preBlue, preGreen);
            blue = costs[i][1] + min(preRed, preGreen);
            green = costs[i][2] + min(preRed, preBlue);
        }

        return min(red, min(blue, green));
    }
};