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
    bool isUnival(TreeNode* root, int uVal) {
        if(!root){
            return true;
        }
        if(root->val!=uVal){
            return false;
        }

        bool left = isUnival(root->left,uVal);
        bool right = isUnival(root->right,uVal);

        if(left && right){
            return true;
        }
        return false;
    }
    bool isUnivalTree(TreeNode* root) {
        int uVal = root->val;
        return isUnival(root->left,uVal) && isUnival(root->right,uVal);
    }
};