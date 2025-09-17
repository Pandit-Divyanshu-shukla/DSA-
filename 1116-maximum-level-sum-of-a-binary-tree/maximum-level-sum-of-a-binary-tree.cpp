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
    int maxLevelSum(TreeNode* root) {

        queue<TreeNode*> q;
        int maxi = INT_MIN;

        int ansLevel = INT_MIN;
        int level = 1;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            int currMax = 0;
            while(size){
                TreeNode* currNode = q.front();
                currMax+=currNode->val;
                size--;
                q.pop();
                if(currNode->left) q.push(currNode->left);
                if(currNode->right) q.push(currNode->right);
            }
            if(maxi<currMax){
                ansLevel = level;
            }
            level++;
            maxi = max(currMax,maxi);
        }

        return ansLevel;
    }
};