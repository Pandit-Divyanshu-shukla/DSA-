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
 #define ull unsigned long long 
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue <pair<TreeNode*,ull>> q;
        q.push({root,0});
        ull maxWidth = 0;
        while(!q.empty()){
            int size = q.size();
            ull stIdx = q.front().second;
            ull endIdx = q.back().second;
            ull currWidth = endIdx - stIdx + 1;

            maxWidth = max(currWidth,maxWidth);
            while(size>0){
                TreeNode* root = q.front().first;
                ull i = q.front().second;
                if(root->left) q.push({root->left,2*i-1});
                if(root->right) q.push({root->right,2*i});
                q.pop();
                size--;
            }
            
        } 
        return maxWidth;
    }
};