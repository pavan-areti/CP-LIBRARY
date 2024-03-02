        queue<TreeNode*> q;
        q.push(root);
        
        int l = 0;
        while(!q.empty()){
            int s = sz(q);
            while(s--){
                auto t = q.front();q.pop();
                if(t->left){
                    q.push(t->left);
                }
                if(t->right){
                    q.push(t->right);
                }
            }
            l++;
        }
