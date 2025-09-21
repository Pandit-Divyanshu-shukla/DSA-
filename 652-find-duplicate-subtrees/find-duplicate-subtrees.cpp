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
    string helper(TreeNode* root, map<string,int> &subTrees, vector<TreeNode*> &ans){
        if(!root){
            return "N";
        }

        string leftPath = helper(root->left, subTrees, ans);
        string rightPath = helper(root->right, subTrees, ans);

        string fullPath = to_string(root->val) + "," + leftPath + "," + rightPath;

        subTrees[fullPath]++;
        if(subTrees[fullPath]==2){
            ans.push_back(root);
        }

        return fullPath;

    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        map<string,int> subTrees;
        vector<TreeNode*>dup;
        helper(root,subTrees,dup);
        return dup;
    }
};