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
    TreeNode* Pre(TreeNode* root){
        TreeNode* curr = root->left;
        while(curr->right && curr->right != root){
            curr = curr->right;
        }
        return curr;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> MIT;
        TreeNode* curr = root;
        while(curr){
            if(curr->left == nullptr){ MIT.push_back(curr->val);
            curr = curr->right;}
            else{
                TreeNode* IP = Pre(curr);
                if(!IP->right){
                    IP->right = curr;
                    curr = curr->left;
                }
                else{
                    IP->right = NULL;
                    MIT.push_back(curr->val);
                    curr = curr->right;
                }

            }
        }
        return MIT;
    }
};