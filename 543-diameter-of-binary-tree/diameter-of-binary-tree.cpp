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
    pair<int,int> diameter(TreeNode* root) {
        
        if(!root) return  make_pair(0,0);

        // Diameter, Height
        pair<int,int> leftInfo = diameter(root->left); //LD,LH
        pair<int,int> rightInfo = diameter(root->right); //RD,RH

        int finalHt = max(leftInfo.second, rightInfo.second) + 1;
        int diaThroughRoot = leftInfo.second + rightInfo.second;

        int dia = max(max(leftInfo.first, rightInfo.first), diaThroughRoot);

        return {dia,finalHt};
    }

    int diameterOfBinaryTree(TreeNode* root) {
        return diameter(root).first;
    }
};