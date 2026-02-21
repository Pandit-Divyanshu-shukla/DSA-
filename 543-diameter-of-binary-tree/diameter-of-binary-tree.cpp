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
#define pii pair<int,int>
class Solution {

    pii diameter(TreeNode* root){
        if(!root) return {0,0};

        pii left = diameter(root->left);
        pii right = diameter(root->right);

        int leftHeight = left.first;
        int leftDiameter = left.second;

        int rightHeight = right.first;
        int rightDiameter = right.second;

        int rootDiameter = leftHeight + rightHeight ;
        int currHeight = max(leftHeight,rightHeight) + 1;

        int currDiameter = max(rootDiameter,max(leftDiameter,rightDiameter));

        return {currHeight,currDiameter};
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return diameter(root).second;
    }
};