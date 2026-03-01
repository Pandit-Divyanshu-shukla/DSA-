class Node{
public:
    bool endOfWord;
    Node* children[26];

    Node(){
        endOfWord = false;
        for(int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* temp = root;

        for(int i = 0; i < word.size(); i++){
            int index = word[i] - 'a';

            if(temp->children[index] == NULL){
                temp->children[index] = new Node();
            }

            temp = temp->children[index];
        }

        temp->endOfWord = true;
    }
    
    bool search(string word) {
        Node* temp = root;

        for(int i = 0; i < word.size(); i++){
            int index = word[i] - 'a';

            if(temp->children[index] == NULL){
                return false;
            }

            temp = temp->children[index];
        }

        return temp->endOfWord;
    }
    
    int count(Node* root){
        int cnt = 1;

        for(int i = 0; i < 26; i++){
            if(root->children[i] != NULL){
                cnt += count(root->children[i]);
            }
        }

        return cnt;
    }
};

class Solution {
public:
    int countSubs(string& s) {
        Trie trie;
        string suffix = "";

        for(int j = s.size() - 1; j >= 0; j--){
            suffix = s[j] + suffix;
            trie.insert(suffix);
        }

        return trie.count(trie.root) - 1;
    }
};