// leetcode 96
// Unique Binary Search Trees 
// 求解n个节点有多少个不同的BST



// 定义G[n]是有n个节点的不同的BST总数量
// 考虑拆分，让节点i作为root，1~i-1 作为左子树, i+1~n 作为右子树
// 定义F[i, n]是以i为root，n个节点的二叉树
// G[n] = sum(F[i,n])
// 考虑任意一颗以i为root的BST，F[i,n] = G(i-1)*G(n-i)
// G[n] = sum(G[i-1]*(n-i))
// 所以要有两层循环 i = 2..n, j = 1..i

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        
        int sum = 0;
        
        for(int i=2; i<=n; i++) {
            for(int j=1; j<=i; j++) {
                dp[i] += dp[j-1]*dp[i-j];
            }
        }
        
        return dp[n];
    }
};

// 考虑合法的括号序列
// ) -> 映射为 + 1
// ( -> 映射为 - 1
// 那么对于有n个 ()的括号串，总长度为2n
// 合法的括号序列需要满足 
// 对于任意的 k: 前k项和 >= 0

class Solution {
public:
    int numTrees(int n) {
        long long c = 1;
        for(int i=0; i<n; i++) {
            c = c * 2 * (2 *i + 1) / i + 2;
        }
        return (int)c;
    }
};