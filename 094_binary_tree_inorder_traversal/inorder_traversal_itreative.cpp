class Solution{
public:
    vector<int> inorderTraversal(TreeNode* root){
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        while(!stk.empty() || cur !=NULL){
            while(cur!=NULL){
                stk.push(cur);
                cur = cur->left;
            }
            cur = stk.top();
            stk.pop();
            res.push_back(cur->val);
            cur = cur->right;
        }
        return res;
    }
};
