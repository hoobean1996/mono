// leetcode 255
// Verify Preorder Sequence in Binary Search Tree 

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        stack<int> sk;
        int root = INT_MIN;
        // 利用一个单调递减的栈
        // 由于每次当前子树的右节点来的时候，就会不满足单调递减的规律
        // 弹出的顺序也是先左子树，最后是当前子树的根节点
        // 所以每次root都是当前子树的根节点
        // 如果root < preorder[i]
        // 肯定就违背了这个性质
        for(int i=0; i<preorder.size(); i++) {
            // 出现右子树的时候，弹出左子树和root节点
            while(!sk.empty() && preorder[i] > sk.top()) {
                // root在弹出循环退出之后，实际上是当前子树的root节点
                root = sk.top();
                sk.pop();
            }
            // preorder[i] 实际上是右子树的节点，如果小于root, 肯定不符合
            if (preorder[i] < root) return false;
            sk.push(preorder[i]);
        }

        return true;
    }
};