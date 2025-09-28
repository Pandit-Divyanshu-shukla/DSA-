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
    TreeNode* helper(vector<int>& preorder,int &idx, int left, int right, unordered_map<int,int>& mp){
        if(left>right){
            return nullptr;
        }
        // curr node ko node bana
        TreeNode* node = new TreeNode(preorder[idx]);
        //phir uska left aur right subtree find kar
        int inIdx = mp[preorder[idx]];
        idx++;

        //phir pehle left tree bana phir right
        // left tree inidx-1 tak hi hoga
        node->left = helper(preorder,idx,left,inIdx-1,mp);
        // phir right bana jo ki inidx+1 se hi hoga
        node->right = helper(preorder,idx,inIdx+1, right, mp);

        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        int idx = 0;
        return helper(preorder,idx,0,preorder.size()-1,mp);
    }
};