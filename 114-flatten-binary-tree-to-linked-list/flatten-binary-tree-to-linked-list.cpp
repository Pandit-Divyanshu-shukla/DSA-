/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flat(TreeNode* root, vector<TreeNode*>& preorder){
        if(!root){
            return ;
        }
        preorder.push_back(root);
        flat(root->left,preorder);
        flat(root->right,preorder);
    }
    void flatten(TreeNode* root) {
        vector<TreeNode*>preorder;
        flat(root,preorder);
        TreeNode* node = root;
        for(auto i=1; i<preorder.size();i++){
            TreeNode* prev = preorder[i-1];
            TreeNode* curr = preorder[i];

            prev->right = curr;
            prev->left  = nullptr;
        }
    }
};