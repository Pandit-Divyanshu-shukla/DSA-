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
    void path(TreeNode* root, vector<string>& ans, string& curr){
        if(!root) return ;
        string prev = curr;
        curr += to_string(root->val) + "->";

        
        path(root->left,ans,curr);
        path(root->right,ans,curr);

        if(!root->left && !root->right){
            string path = prev + to_string(root->val);
            ans.push_back(path);
        }
        curr = prev;

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string currPath = "";
        path(root,ans,currPath);
        return ans;
    }
};