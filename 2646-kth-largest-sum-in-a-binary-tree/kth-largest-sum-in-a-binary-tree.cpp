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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;

        vector<long long>m;

        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            long long currMax = 0;
            while(size){
                TreeNode* currNode = q.front();
                currMax+=currNode->val;
                size--;
                q.pop();
                if(currNode->left) q.push(currNode->left);
                if(currNode->right) q.push(currNode->right);
            }
            m.push_back(currMax);
        }
        sort(m.begin(),m.end(),greater<long long>());
        if(k>m.size()){
            return -1;
        }
        return m[k-1];
    }
};