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
    TreeNode* IP(TreeNode* root){
        while(root->right){
            root = root->right;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        if(root->val>key){
            root->left = deleteNode(root->left,key);
        }
        else if(root->val<key){
            root->right = deleteNode(root->right,key);
        }
        else{

            TreeNode* l = root->left;
            TreeNode* r = root->right;

            if(!l && !r){
                delete root;
                return nullptr;
            }

            if((!l && r) || (l && !r)){
                return (!l) ? r : l; 
            }

            TreeNode* pred = IP(root->left);
            root->val = pred->val;
            root->left = deleteNode(root->left,pred->val);

            return root;

        }
        return root;
    }
};