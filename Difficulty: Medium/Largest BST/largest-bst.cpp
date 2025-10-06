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
            // validate hnn hai
            // max of left -> int min
            // min of right -> int max
            // size of current -> nhi h node isilye 0
            return {1,INT_MIN,INT_MAX,0};
        }
        
        vector<int> leftInfo = info(root->left);
        vector<int> rightInfo = info(root->right);
        
        vector<int> info(4,0);
        
        Node* currNode = root;
        
        // if currnode is in range and left and right both valid 
        // Then give the updated values of Current Node
        // i.e Valid, max of left, min of right, and size of current Node resp
        
        if(leftInfo[0] && rightInfo[0] && leftInfo[1] < currNode->data && 
        currNode->data < rightInfo[2]){
            // Valid
            info[0]=1;
            info[1] = max(currNode->data,max(leftInfo[1],rightInfo[1]));
            info[2] = min(currNode->data,min(leftInfo[2],rightInfo[2]));
            info[3] = 1 + leftInfo[3] + rightInfo[3]; 
        }
        else{
            info = {0,INT_MIN,INT_MAX,0}; 
        }
        
        maxSize = max(maxSize,info[3]);
        
        return info;
    }
    int largestBst(Node *root) {
        // Your code here
        info(root);
        return maxSize;
        
    }
};