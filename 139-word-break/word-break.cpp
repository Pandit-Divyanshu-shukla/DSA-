class Solution {
public:
    struct Node{
        bool endOfWord;

        unordered_map <char,Node*> children;

        Node(){
            endOfWord = false;
        }
    };
    struct Trie{
        Node* root;

        Trie(){
            root = new Node();
        }
        void insert(string key){
            Node* temp = root;
            for(int i=0; i<key.size(); i++){
                if(temp->children.count(key[i])==0){
                    temp->children[key[i]] = new Node();
                }
                temp = temp->children[key[i]];
            }
            temp->endOfWord = true;
        }

        bool search(string key){
            Node* temp = root;
            for(int i=0; i<key.size(); i++){
                if(temp->children.count(key[i])==0){
                    return false;
                }
                temp = temp->children[key[i]];
            }
            return temp->endOfWord;
        }
    };

    bool isFound(string s, Trie& trie, unordered_map<string, bool>& dp){ //O(2^n)
        if(dp.count(s)) return dp[s];
        
        if(s.size()==0){
            return true;
        }
        for(int i=0; i<s.size(); i++){ //O(n)

            string left = s.substr(0,i+1); //O(n)
            string right = s.substr(i+1);

            if(trie.search(left)){
                if(isFound(right,trie,dp)){
                    dp[s] = true;
                    return true;
                }
            }
        }
        dp[s]=false;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie trie;
        string key = s;
        Node* temp = trie.root;
        unordered_map<string, bool> dp;
        for(string &st: wordDict){
            trie.insert(st);
        }
        return isFound(s,trie,dp);
    }
};