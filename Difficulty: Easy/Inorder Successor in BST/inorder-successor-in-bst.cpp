/*The structure of Node

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
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    int IS(Node* root){
        if(!root){
            return -1;
        }
        while(root->left){
            root = root->left;
        }
        return root->data;
    }
    int inOrderSuccessor(Node *root, Node *x) {
        // Your code here
        int succ = -1;
        if(root->data == x->data){
            succ = IS(root->right);
        }
        else if(root->data>x->data){
            int leftsucc = inOrderSuccessor(root->left,x);
            return (leftsucc!=-1) ? leftsucc : root->data;
        }
        else{
            succ = inOrderSuccessor(root->right,x);
        }
        return succ;
    }
};