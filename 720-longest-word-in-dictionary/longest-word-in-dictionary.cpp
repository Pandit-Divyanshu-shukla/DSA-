class Node{
public:
    bool EOW;
    unordered_map <char, Node*> children;
    Node(){
        EOW = false;
    }
};
class Trie{
    
public:
    Node* root;

    Trie(){
        root = new Node();
    }
    
    void insert(string word){
        Node* temp = root;
        for(int i=0; i<word.size(); i++){
            if(temp->children.count(word[i])==0){
                temp->children[word[i]] = new Node();
            }
            temp = temp->children[word[i]];
        }
        temp->EOW = true;
    }
    
    bool search(string word){
        Node* temp = root;
        for(int i=0; i<word.size(); i++){
            if(temp->children.count(word[i])==0){
                return false;
            }
            temp = temp->children[word[i]];
        }
        return temp->EOW;
    }
    
    void solve(Node* root, string& ans, string& temp){
        for(auto &it: root->children){
            if(it.second->EOW){
                temp.push_back(it.first);
                if(temp.size()>ans.size()){
                    ans = temp;
                }
                else if(temp.size()==ans.size()){
                    ans = temp<ans ? temp : ans;
                }
                solve(it.second,ans,temp);
                temp.pop_back();
            }
        }
        
    }
};
class Solution {
  public:
    string longestWord(vector<string> &words) {
        // code here
        Trie trie;
        for(string &st: words){
            trie.insert(st);
        }
        string ans = "";
        string temp = "";
        trie.solve(trie.root,ans, temp);
        
        return ans;
        
    }
};