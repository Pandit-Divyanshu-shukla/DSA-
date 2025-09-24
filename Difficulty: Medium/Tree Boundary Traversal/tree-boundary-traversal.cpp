/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void leftNodes(Node *root, vector<int> &left){
        if(root==NULL) return;
        //Excluding leaves
        if(!root->left && !root->right){
            return ; 
        }
        left.push_back(root->data);   
        
        if(root->left) leftNodes(root->left, left);
        else if(root->right) leftNodes(root->right, left);

    }
    
    void leafNodes(Node *root, vector<int> &leaves){
        if(root==NULL) return;
        //leaves
        if(!root->left && !root->right){
            leaves.push_back(root->data);  
            return;
        }
        
        leafNodes(root->left, leaves);
        leafNodes(root->right, leaves);
    }
    
    void rightNodes(Node *root, vector<int> &right){
        if(root==NULL) return;
        //Excluding leaves
        if(!root->left && !root->right){
            return ; 
        }
        
        if(root->right) rightNodes(root->right, right);
        else if(root->left){
            rightNodes(root->left, right);
        }
        right.push_back(root->data);   
        
    }
    
    
    vector<int> boundaryTraversal(Node *root) {
        
        vector<int> ans;
        if(!root){
            return ans;
        }
        
        if(root && !root->left && !root->right){
            ans.push_back(root->data); 
            return ans;
        }
        // code here
        vector<int> left;
        vector<int> right;
        vector<int> leaves;
        
        
        if(root->left) leftNodes(root->left,left);
        leafNodes(root,leaves);
        if(root->right) rightNodes(root->right,right);
        
        ans.push_back(root->data);  // root is always part of boundary
        ans.insert(ans.end(), left.begin(), left.end());
        ans.insert(ans.end(), leaves.begin(), leaves.end());
        ans.insert(ans.end(), right.begin(), right.end());
        
        return ans;
        
    }
};