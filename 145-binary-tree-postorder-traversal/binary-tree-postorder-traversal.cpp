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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root){
            return ans;
        }
        
        stack<TreeNode*> st;
        TreeNode* lastVisitedNode = nullptr;

        TreeNode* curr = root;

        while(curr || !st.empty()){
            if(curr){
                st.push(curr);
                curr = curr->left;
            }
            else{
                TreeNode* top = st.top();
                if(top->right == nullptr || top->right == lastVisitedNode){
                    ans.push_back(top->val);
                    st.pop();
                    lastVisitedNode = top;
                }
                else{
                    curr = top->right;
                }
            }
        }

        return ans;
    }
};