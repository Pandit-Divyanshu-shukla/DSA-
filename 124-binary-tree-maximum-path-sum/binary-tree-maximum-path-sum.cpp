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
    int helper(TreeNode* root, int& maxPath) {
        if(!root){
            return 0;
        }

        int leftPath = max(0,helper(root->left,maxPath));
        int rightPath = max(0,helper(root->right,maxPath));
        int currPath = root->val + leftPath + rightPath;
        maxPath = max(currPath,maxPath);

        return root->val + max(leftPath,rightPath);
    }
    int maxPathSum(TreeNode* root) {
        int maxPath = INT_MIN;
        helper(root,maxPath);
        return maxPath;
    }
};