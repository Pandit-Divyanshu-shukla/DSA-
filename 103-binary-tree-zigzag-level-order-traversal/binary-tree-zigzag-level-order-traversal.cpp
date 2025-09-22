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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root){
            return ans;
        }
        queue <TreeNode*> q;
        q.push(root);
        bool reverseLevel = false;
        while(!q.empty()){
            int size = q.size();
            vector<int> currLevel;
            while(size){
                TreeNode* node = q.front();
                currLevel.push_back(node->val);
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                size--;
            }
            if(reverseLevel){
                reverse(currLevel.begin(), currLevel.end());
            }
            reverseLevel = !reverseLevel;
            ans.push_back(currLevel);
        }
        return ans;
    }
};