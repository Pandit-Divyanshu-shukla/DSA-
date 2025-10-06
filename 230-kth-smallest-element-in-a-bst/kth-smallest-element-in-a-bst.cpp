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
    int count = 0;
    void inorder(TreeNode* root, vector<int>& iorder, int k){
        if(!root) return ;
        
        inorder(root->left,iorder,k);
        iorder.push_back(root->val);
        count++;
        if(count==k){
            return;
        }
        inorder(root->right,iorder,k);
        
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> inorder1;
        inorder(root,inorder1,k);
        return inorder1[k-1];
    }
};