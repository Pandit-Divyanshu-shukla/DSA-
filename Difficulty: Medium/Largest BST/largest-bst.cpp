/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int maxSize = 0;
    vector<int> info(Node* root){
        if(!root){
            return {1,INT_MAX,INT_MIN,0};
        }
        vector<int> leftInfo = info(root->left);
        vector<int> rightInfo = info(root->right);
        
        vector<int> info(4,0);
        
        if(leftInfo[0] && rightInfo[0] && root->data > leftInfo[2] && root->data < rightInfo[1]){
            info[0] = 1;
            info[1] = min(root->data, min(leftInfo[1],rightInfo[1]));
            info[2] = max(root->data, max(leftInfo[2],rightInfo[2]));
            info[3] = 1 + leftInfo[3] + rightInfo[3];
        }
        else{
            info[0] = 0;
            info[1] = INT_MAX;
            info[2] = INT_MIN;
            info[3] = 0;
        }
        
        maxSize = max(info[3],maxSize);
        
        return info;
    }
    int largestBst(Node *root) {
        // Your code here
        info(root);
        return maxSize;
        
    }
};