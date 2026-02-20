class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int> correct;
        string ans;
        int bull = 0;
        int cow=0;
        for(char ch: secret){
            correct[ch]++;
        }

        for(int i=0; i<secret.length(); i++){
            if(secret[i]==guess[i]){
                bull++;
                correct[secret[i]]--;
            }
        }
        for(int i=0; i<secret.length(); i++){
            if(secret[i]!=guess[i]){
                if(correct[guess[i]]){
                    //exists
                    cow++; 
                    correct[guess[i]]--;
                }
            }
            
        }
        
        ans = to_string(bull) + "A" + to_string(cow) + "B";
        return ans;
    }
};