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
            return "#";
        }

        string left = helper(root->left,subTrees,ans);
        string right = helper(root->right, subTrees,ans);
        string currNode = to_string(root->val);

        string path = currNode+","+left+","+right;
        if(subTrees[path]==1){
            ans.push_back(root);
        }
        subTrees[path]++;

        return path;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        map<string,int> subTrees;
        vector<TreeNode*>dup;
        helper(root,subTrees,dup);
        return dup;
    }
};