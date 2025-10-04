/*
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
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    void inorder(Node* root, vector<int>& iorder){
        if(!root) return ;
        
        inorder(root->left,iorder);
        iorder.push_back(root->data);
        inorder(root->right,iorder);
        
    }
    vector<int> merge(Node *root1, Node *root2) {
        
        // Your code here
        vector <int> inorder1;
        vector<int> inorder2;
        
        inorder(root1, inorder1);
        inorder(root2, inorder2);
        
        vector<int> res;
        
        int id1 = 0;
        int id2 = 0;
        while(id1<inorder1.size() && id2<inorder2.size()){
            if(inorder1[id1]<inorder2[id2]){
                res.push_back(inorder1[id1++]);
            }
            else{
                res.push_back(inorder2[id2++]);
            }
        }
        
        while(id1<inorder1.size()){
            res.push_back(inorder1[id1++]);
        }
        
        while(id2<inorder2.size()){
            res.push_back(inorder2[id2++]);
        }
        
        return res;
        
    }
};