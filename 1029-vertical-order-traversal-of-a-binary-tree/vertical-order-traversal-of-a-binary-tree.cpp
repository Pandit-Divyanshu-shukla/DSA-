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
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pair<int,int>>> m;
        queue<tuple<TreeNode*, int, int>> q; 

        vector<vector<int>> ans;

        q.push({root,0,0});

        while(!q.empty()){
            int row = get<1>(q.front());
            TreeNode* node = get<0>(q.front());
            int col = get<2>(q.front());

            m[col].push_back({row,node->val});
            q.pop();

            if(node->left) q.push({node->left,row+1,col-1});
            if(node->right) q.push({node->right, row+1, col+1});
        }

        for(auto it: m){
            int col = it.first;
            auto vec = it.second;
            sort(vec.begin(), vec.end());
            vector<int> temp;
            for(auto &[r,node] : vec){
                temp.push_back(node);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};