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
    TreeNode* BTH(vector<int>& postorder,int &postIdx,int left, int right, unordered_map<int,int> &mp){
        if(left>right){
            return nullptr;
        }
        TreeNode* root = new TreeNode(postorder[postIdx]);
        int inIdx = mp[postorder[postIdx]];
        postIdx--;

        
        root->right = BTH(postorder,postIdx,inIdx+1,right,mp);
        root->left = BTH(postorder,postIdx,left,inIdx-1,mp);
        

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postIdx = postorder.size() - 1;
        unordered_map<int,int> mp;
        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        return BTH(postorder,postIdx,0,postorder.size() - 1,mp);
    }
};