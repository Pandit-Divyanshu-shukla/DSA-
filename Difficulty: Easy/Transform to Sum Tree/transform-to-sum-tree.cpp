/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:

    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    int helper(Node* node){
        if(!node){
            return 0;
        }
        
        int leftSum = helper(node->left);
        int rightSum = helper(node->right);
        
        int currNode = node->data;
        node->data = leftSum + rightSum;
        
        return currNode+leftSum+rightSum;
    }
    void toSumTree(Node *node) {
        // Your code here
        helper(node);
    }
};