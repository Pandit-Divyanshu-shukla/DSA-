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

    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int &preIdx, int left, int right, unordered_map<int,int>& mp) {
        if(left>right){
            return nullptr;
        }
        TreeNode* root = new TreeNode (preorder[preIdx]);
        int inIdx = mp[preorder[preIdx]];
        preIdx++;

        root->left = buildTreeHelper(preorder,inorder,preIdx,left,inIdx-1,mp);
        root->right = buildTreeHelper(preorder,inorder,preIdx,inIdx+1,right,mp);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx = 0;
        unordered_map<int,int> mp;
        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        return buildTreeHelper(preorder,inorder,preIdx,0,preorder.size()-1,mp);
    }
};