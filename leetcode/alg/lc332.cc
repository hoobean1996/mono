// leetcode 332
// Reconstruct Itinerary
// 重新构建航线
// 给定很多张票，每张票都是 [from, to] 的格式
// 分别代表的是起点和终点
// 我们想要构建成一个线性的路线
// 欧拉路径：如果图G的一个路径恰好包含每个边一次，则该路径就是欧拉路径
// 计算欧拉路径的算法：选中一个合法的起点，进行DFS，同时每搜完一条边，就将其他从图中删除
// 同时考察此条路径是否搜索完成，如果是的话，就把该节点放入到结果列表
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    map<string, vector<string>> flightMap;
    vector<string> result;
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // 首先把图构建好
        // origin -> dest, dest, dest
        for(vector<string> ticket: tickets) {
            string origin = ticket[0];
            string dest = ticket[1];
            
            flightMap[origin].push_back(dest);
        }
        
        // 对于图中的每个点，我们都把所有的终点按照字符串顺序排序
        for(auto& item: flightMap) {
            // 每个节点的相邻节点按照字符串顺序排序
            sort(item.second.begin(), item.second.end(), [](const string& f1, const string& f2){
                return f1 < f2;
            });
            // 为了让之后pop_back能够快速完成
            reverse(item.second.begin(), item.second.end());
        }
        
        // 从JFK起点开始
        dfs("JFK");
        
        
        return vector<string>(result.rbegin(), result.rend());
    }
    
    // 欧拉路径
    // 选择一个合法的起点，然后进行dfs
    // 每次搜索完一条边，就删除
    // 如果不能去更多的边
    // 就把当前节点加入结果
    void dfs(string origin) {
        // 如果当前起点有可达的终点
        while(flightMap[origin].size() > 0) {
            string dest = flightMap[origin].back(); flightMap[origin].pop_back();
            dfs(dest);
        }
        result.push_back(origin);
    }
};
