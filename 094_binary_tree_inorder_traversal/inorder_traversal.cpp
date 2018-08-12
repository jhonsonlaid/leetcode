/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution{
public:
    vector<int> inorderTraversal(TreeNode* root){
        vector<int> res;
        recursiveTraversal(root, res);
        return res;
    }

    void recursiveTraversal(TreeNode* root, vector<int>& res){
        if(root == NULL)
            return;
        if(root->left != NULL)
            recursiveTraversal(root->left, res);
        res.push_back(root->val);
        if(root->right != NULL)
            recursiveTraversal(root->right, res);
    }
};
