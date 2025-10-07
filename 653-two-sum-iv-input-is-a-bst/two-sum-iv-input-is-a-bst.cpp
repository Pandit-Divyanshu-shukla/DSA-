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
    bool search(TreeNode* root, TreeNode* curr, int target){
        if(!root) return false;
        if(root != curr && root->val == target){
            return true;
        }
        if(target<root->val){
            return search(root->left,curr,target);
        }
        else{
            return search(root->right,curr,target);
        }
        
    }
    bool helper(TreeNode* root, TreeNode* mainRoot, int k){
        if(!root) return false;
        int target = k - root->val;
        bool found = search(mainRoot,root,target);

        if(found) return true;
 
        return helper(root->left,mainRoot, k) || helper(root->right,mainRoot, k);
    }
    bool findTarget(TreeNode* root, int k) {
        return helper(root,root,k);
    }
};