// leetcode 218
// 天际线问题


// Divide and Conquer 
// - Define the base case(s)
// - Split the problem into subproblems and solve them recursively
// - Merge the subproblems 

// n == 0 return {}
// n == 1 return for one building
// left, right
// merge

#include <bits/stdc++.h>

using namespace std;

// Events = 左端点 {L, H, Entering}
// Events = 右端点 {R, H, Leaving} 

// Events.sortByX()
// ds = new DS()
// for e in events:
//  if entering(e):
//      if e.height > ds.max(): ans += [e.height]
//      ds.add(e.height)
//  if leaving(e):
//      ds.remove(e.height)
//      if e.height > ds.max(): ans += [maxHeight()]


// 首先需要明确 critical points只能出现在边缘点
// 用一根垂直于x轴去滑动
// 如果是进入点，我们需要看第一高的点
// 如果是离开点，我们需要看第二高的点 相当于把自己移除之后的最大点
// 所以我们需要一个数据结构来存储遍历到点所有点的高度
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        // 定义Event
        // X是横坐标
        // H是高度
        typedef pair<int, int> Event; // x, h

        vector<Event> es;
        hs_.clear();

        // 遍历每个建筑，转换为一个Event
        for(const auto& b: buildings) {
            // Entering
            es.emplace_back(b[0], b[2]);
            // Leaving
            es.emplace_back(b[1], -b[2]);
        }

        // 按照event的信息进行排序
        // 如果两个event的横坐标相同，返回较高的一个
        // 否则的话，返回横坐标较小的一个
        sort(es.begin(), es.end(), [](const Event& e1, const Event& e2){
            if (e1.first == e2.first) return e1.second > e2.second;
            return e1.first < e2.first;
        });

        vector<vector<int>> ans;

        for(const auto& e: es) {
            int x = e.first;

            bool entering = e.second > 0;
            int h = abs(e.second);

            if (entering) {
                if (h > maxHeight()) ans.push_back({x, h});
                hs_.insert(h);
            } else {
                hs_.erase(hs_.equal_range(h).first);
                if (h > maxHeight()) ans.push_back({x, maxHeight()});
            }
        }

        return ans;
    }

    // rbegin 可以返回最大值
    int maxHeight() const {
        if (hs_.empty()) return 0;
        return *hs_.rbegin();
    }

    // multiset 有序集合，同时可以存放多个相同的值
    multiset<int> hs_;
};