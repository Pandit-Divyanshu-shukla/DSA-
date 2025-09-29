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
    TreeNode* IS(TreeNode* root){
        if(!root) return nullptr;
        while(root->left){
            root = root->left;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root){
            return nullptr;
        }
        if(key>root->val){
            root->right = deleteNode(root->right,key);
        }
        else if(key<root->val){
            root->left = deleteNode(root->left,key);
        }
        else{
            //root==key

            TreeNode* left = root->left;
            TreeNode* right = root->right;

            // Case 1 : 0 child
            if(!left && !right){
                delete root;
                return nullptr;
            }

            //Case 2 : 1 child
            if(!left && right){
                return right;
            }

            if(left && !right){
                return left;
            }

            //Case 2 : 2 Child
            TreeNode* succ = IS(root->right);
            root->val = succ->val;
            root->right = deleteNode(root->right,succ->val);
            // delete succ;

            }
        return root;
    }
};