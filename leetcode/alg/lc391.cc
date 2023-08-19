// leetcode 391
// Perfect Rectangle 

#include <bits/stdc++.h>
using namespace std;

// 维护最大的正方形的左下角 和 右上角的点
// (x1, y1) and (x2, y2)
// 然后遍历所有的矩型
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        set<pair<int, int>> lookup;
        
        int x1 = INT_MAX;
        int y1 = INT_MAX;
        
        int x2 = INT_MIN;
        int y2 = INT_MIN;
        
        long long area = 0;
        
        for(const auto& rec: rectangles) {
            int x = rec[0];
            int y = rec[1];
            int s = rec[2];
            int t = rec[3];
            
            // 构造(x1, y1) (x2, y2)
            x1 = min(x1, x);
            y1 = min(y1, y);
            x2 = max(x2, s);
            y2 = max(y2, t);
            
            // 当前矩形的面试是这么多
            area += (long long)(t - y) * (s - x);
            
            vector<pair<int,int>> points = {{x, y}, {x, t}, {s, y}, {s,t}};
            // 由于我们已经通过(x1, x2)维护了最外层的点
            for(const auto& item: points) {
                // 如果没有就加入，如果有 就删除
                // 内部的点会抵消
                if (lookup.find(item) == lookup.end()) lookup.insert(item);
                else lookup.erase(item);
            }
        }
        
        // 最后应该是保留四个点，并且分别和(x1, y1) and (x2, y2)所形成的正方形一致
        if (lookup.size() != 4 or
            lookup.find({x1, y1}) == lookup.end() or
            lookup.find({x1, y2}) == lookup.end() or
            lookup.find({x2, y1}) == lookup.end() or
            lookup.find({x2, y2}) == lookup.end()) return false;
        return (long long)(x2 - x1) * (long long)(y2 - y1) == area;
    }
};