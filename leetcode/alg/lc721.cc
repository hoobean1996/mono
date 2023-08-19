// leetcode 721
// Account Merge

// 给定一组账号，每组账号都是一组字符串，其中第一个字符串是名字，之后的字符串都是和该名字绑定的
// 邮箱。
// 我们想把这些账号合并，两个账号可以merge的条件就是如果他们有一个公共的账号。

/*
accounts = 
[
    ["John","johnsmith@mail.com","john_newyork@mail.com"],
    ["John","johnsmith@mail.com","john00@mail.com"],
    ["Mary","mary@mail.com"],
    ["John","johnnybravo@mail.com"]
]

Output: 
[
    ["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],
    ["Mary","mary@mail.com"],
    ["John","johnnybravo@mail.com"]]

*/

// leetcode 721
// Account Merge

/*
accounts = 
[
    ["John","johnsmith@mail.com","john_newyork@mail.com"],
    ["John","johnsmith@mail.com","john00@mail.com"],
    ["Mary","mary@mail.com"],
    ["John","johnnybravo@mail.com"]
]

Output: 
[
    ["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],
    ["Mary","mary@mail.com"],
    ["John","johnnybravo@mail.com"]]

*/

#include <bits/stdc++.h>

using namespace std;

class UFS {
private:
    vector<int> fa;

public:
    UFS(int size) {
        fa = vector<int>(size);
        for(int i=0; i<size; i++) fa[i] = i;
    }

    int find(int x) {
        if (fa[x] != x) fa[x] = find(fa[x]);
        return fa[x];
    }
    

    void merge(int x, int y) {
        int a = find(x);
        int b = find(y);

        if (a != b) {
            fa[b] = a;
        }
    }
};

class Solution {
public:
    // 我们可以利用在同一个名字下的邮箱 做并查集
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // 初始化并查集
        // accounts的下标对应不同的group
        UFS ufs(accounts.size());

        // email -> group的映射
        // 由于是按照邮箱来识别一个人的，所以我们需要使用一个
        unordered_map<string, int> group;

        for(int i=0; i<accounts.size(); i++) {
            for(int j=1; j<accounts[i].size(); j++) {
                string email = accounts[i][j];
                // 如果该email还不存在，就建立一个email -> i的映射
                if (group.find(email) == group.end()) group[email] = i;
                // 如果已经存在，就把当前的group i 和已经存在的group[email]进行merge
                else ufs.merge(i, group[email]);
            }
        }

        // group记录了email -> group的映射
        //  可以出现多个email -> 相同的group的映射
        //  fa记录了不同group之间的关系

        // comps 记录了group -> emails 的关系
        // 由于我们已经有group的信息
        // 遍历group反向存储即可
        unordered_map<int, vector<string>> comps;
        // 遍历group，
        for(auto it: group) {
            string email = it.first;
            int g = it.second;
            comps[ufs.find(g)].push_back(email);
        }

        vector<vector<string>> ans;
        
        // comps 记录了 group -> emails的关系
        // group也是下标
        for(auto it: comps) {
            // 利用下标找到name
            int g = it.first;
            vector<string> compo = {accounts[g][0]};
            // 然后把所有的emails存入进去
            compo.insert(compo.end(), it.second.begin(), it.second.end());
            sort(compo.begin() + 1, compo.end());
            ans.push_back(compo);
        }

        return ans;
    }
};