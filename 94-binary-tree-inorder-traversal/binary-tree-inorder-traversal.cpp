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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        // st.push(root);
        vector<int> ans;

        TreeNode* curr = root;
        while(curr || !st.empty()){
            while(curr){
                st.push(curr);
                curr = curr->left;
            }
            
            TreeNode* top = st.top();
            st.pop();

            ans.push_back(top->val);
            curr = top->right;
        }
        return ans;
    }
};