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

    bool helper(TreeNode* root, int k, unordered_set<int>& seen){
        if(!root) return false;
        int target = k - root->val;
        
        if(seen.count(target)) return true;

        seen.insert(root->val);
 
        return helper(root->left,k,seen) || helper(root->right,k,seen);
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> seen;
        return helper(root,k,seen);
    }
};