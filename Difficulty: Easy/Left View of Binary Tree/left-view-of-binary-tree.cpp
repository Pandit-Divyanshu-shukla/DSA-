/*

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
 */

class Solution {
  public:
    vector<int> leftView(Node *root) {
        vector<int> ans;
        if(!root){
            return ans;
        }
        // code here
        queue<Node*> q;
        q.push(root);
        
        
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                Node* curr = q.front();
                if(i==0) ans.push_back(curr->data);
                q.pop();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
        return ans;
    }
};