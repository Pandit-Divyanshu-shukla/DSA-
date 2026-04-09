class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mp;

        for(char ch: ransomNote){
            mp[ch]++;
        }

        for(char ch: magazine){
            if(mp.count(ch)!=0){
                mp[ch]--;
            }
        }

        for(auto &p: mp){
            if(p.second>0){
                return false;
            }
        }

        return true;


    }
};