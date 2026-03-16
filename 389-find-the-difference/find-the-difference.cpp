class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> count(26,0);
        char ans;
        for(char ch: t){
            count[ch-'a']++;
        }
        for(char ch: s){
            count[ch-'a']--;
        }
        for(int i=0; i<26; i++){
            if(count[i]==1){
                ans = 'a'+i;
            }
        }
        return ans;
    }
};