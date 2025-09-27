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
    int search(TreeNode* root, vector<int>& inorder, int left, int right){
        int inIdx;
        for(int i=left; i<=right; i++){
            if(inorder[i]==root->val){
                inIdx = i;
                break;
            }
        }
        return inIdx;
    }
    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int &preIdx, int left, int right) {
        if(left>right){
            return nullptr;
        }
        TreeNode* root = new TreeNode (preorder[preIdx]);
        preIdx++;

        int inIdx = search(root,inorder,left,right);

        root->left = buildTreeHelper(preorder,inorder,preIdx,left,inIdx-1);
        root->right = buildTreeHelper(preorder,inorder,preIdx,inIdx+1,right);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx = 0;
        return buildTreeHelper(preorder,inorder,preIdx,0,preorder.size()-1);
    }
};