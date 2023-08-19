// leetcode 1522
// Diameter of N-ary Tree

// 考虑任意一个节点，在它的儿子中的最大高度和次最大高度
// 形成的是经过当前节点的最大直径。
// 所以我们需要在所有儿子节点中找到最大和次大即可
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int ans = 0;
    

    int dfs(Node* node) {
        if (node->children.size() == 0) return 0;
        
        int max1 = 0;
        int max2 = 0;
        
        for(Node* child: node->children) {
            // 如果选择当前的儿子的路径，那么该node节点的高度为
            // dfs(child) + 1
            // 然后我们需要在所有儿子的节点的情况下，找到高度的最大情况 和 第二大情况
            int h = dfs(child) + 1;
            if (h > max1) {
                max2 = max1;
                max1 = h;
            }
            else if (h > max2) max2 = h; 
            
            int path = max1 + max2;
            ans = max(ans, path);
        }
        return max1;
    }
    
    int diameter(Node* root) {
        dfs(root);
        return ans;
    }
};

