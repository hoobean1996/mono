TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return nullptr;
        
        int root = preorder[0];
        
        vector<int> leftinorder;
        vector<int> rightinorder;
        
        bool l = true;
        for(int i=0; i<inorder.size(); i++) {
            if (inorder[i] == root) {
                l = false;
                continue;
            }
            
            if (l) leftinorder.push_back(inorder[i]);
            else rightinorder.push_back(inorder[i]);
        }
        
        vector<int> leftpreorder;
        vector<int> rightpreorder;
        
        for(int i=1; i<preorder.size(); i++) {
            if (leftpreorder.size() < leftinorder.size()) leftpreorder.push_back(preorder[i]);
            else rightpreorder.push_back(preorder[i]);
        }    
        
        TreeNode* r = new TreeNode(root, nullptr, nullptr);
        
        TreeNode* left = buildTree(leftpreorder, leftinorder);
        TreeNode* right = buildTree(rightpreorder, rightinorder);
        r->left = left;
        r->right = right;
        return r;
    }