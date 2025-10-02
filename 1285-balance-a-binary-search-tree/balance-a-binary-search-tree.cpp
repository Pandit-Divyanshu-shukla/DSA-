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
    vector<int> in;
    void inorder(TreeNode* root){
        if(!root) return ;

        inorder(root->left);
        in.push_back(root->val);
        inorder(root->right);
    }
    TreeNode* helper(int st, int end){
        if(st>end) return nullptr;
        int mid = st + (end-st)/2;
        TreeNode* root = new TreeNode(in[mid]);

        root->left = helper(st,mid-1);
        root->right = helper(mid+1,end);

        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return helper(0,in.size()-1);
    }
};