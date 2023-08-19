// leetcode 117
// Populating Next Right Pointers in Each Node II

void bfs(Node* root) {
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()) {
            int n = q.size();
            vector<Node*> tmp;
            for(int i=0; i<n; i++) {
                Node* top = q.front();
                q.pop();
                tmp.push_back(top);
                if (top->left) q.push(top->left);
                if (top->right) q.push(top->right);
            }
            
            for(int i=0; i<tmp.size()-1; i++) tmp[i]->next = tmp[i+1];
        }
    }
    
    Node* connect(Node* root) {
        if (!root) return root;
        bfs(root);
        return root;
    }