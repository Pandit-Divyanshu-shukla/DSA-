/*
Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    // Function to find the least absolute difference between any node
    // value of the BST and the given integer.
    int minDif = INT_MAX;
    int minDiff(Node *root, int K) {
        // Your code here
        if(!root){
            return minDif;
        }
        
        minDif = min(minDif,abs(K-root->data));
        
        if(K>root->data) minDiff(root->right,K);
        else if(K<root->data) minDiff(root->left,K);
        else return 0;
        
        return minDif;
    }
};