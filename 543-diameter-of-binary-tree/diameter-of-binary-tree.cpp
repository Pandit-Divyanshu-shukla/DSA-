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
    int ans;
    pair<int,int> diameterfBinaryTree(TreeNode* root) {
        
        if(!root) return {0,0};
        pair<int,int> leftD = diameterfBinaryTree(root->left);
        pair<int,int> rightD = diameterfBinaryTree(root->right);

        int rootD = leftD.first + rightD.first;
        int currH = 1 + max(leftD.first,rightD.first);  

        int currD = max(max(rootD,leftD.second),rightD.second);
        ans = currD;

        return {currH, currD};
    }
    int diameterOfBinaryTree(TreeNode* root) {
        diameterfBinaryTree(root);
        return ans;
        
    }
};