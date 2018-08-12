class Solution{
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root){
        vector<vector<int>> res;
        queue<TreeNode*> parent;
        if(root != NULL){
            parent.push(root);
        }
        while(!parent.empty()){
            queue<TreeNode*> child;
            vector<int> level_res;
            while(!parent.empty()){
                TreeNode* tmp = parent.front();
                parent.pop();
                level_res.push_back(tmp->val);
                if(tmp->left) child.push(tmp->left);
                if(tmp->right) child.push(tmp->right);
            }
            if(!level_res.empty()) res.push_back(level_res);
            parent = child;
        }
        vector<vector<int>> reverse_res;
        int n = res.size();
        for(int i = 0; i < n; i++){
            reverse_res.push_back(res[n-1-i]);
        }
        return reverse_res;
    }
};
