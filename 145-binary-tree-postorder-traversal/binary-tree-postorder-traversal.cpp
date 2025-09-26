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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root){
            return ans;
        }
        
        stack<TreeNode*> left;
        stack<TreeNode*> right;

        left.push(root);
        
        while(!left.empty()){
            TreeNode* curr = left.top(); left.pop();
            right.push(curr);

            if(curr->left) left.push(curr->left);
            if(curr->right) left.push(curr->right);
        }

        while(!right.empty()){
            ans.push_back(right.top()->val);
            right.pop();
        }

        return ans;
    }
};