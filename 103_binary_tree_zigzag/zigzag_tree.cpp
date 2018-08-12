struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root){
        vector<vector<int>> res;
        stack<TreeNode*> left, right;
        if(root != NULL)
            left.push(root);
        while(!(left.empty() && right.empty())){
            vector<int> lv, rv;
            while(!left.empty()){
                TreeNode* tmp = left.top();
                left.pop();
                lv.push_back(tmp->val);
                if (tmp->left != NULL)
                    right.push(tmp->left);
                if (tmp->right != NULL)
                    right.push(tmp->right);
            }
            while(!right.empty()){
                TreeNode* tmp = right.top();
                right.pop();
                rv.push_back(tmp->val);
                if (tmp->right != NULL)
                    left.push(tmp->right);
                if (tmp->left != NULL)
                    left.push(tmp->left);
            }
            if(lv.size() > 0)
                res.push_back(lv);
            if(rv.size() > 0)
                res.push_back(rv);
        }
        return res;
    }
};
