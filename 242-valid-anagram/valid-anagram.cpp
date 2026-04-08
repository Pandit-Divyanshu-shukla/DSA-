class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map <int,int> mp;
        if(s.length()!=t.length()){
            return false;
        }
        for(char ch: s){
            mp[ch]++;
        }

        for(char ch: t){
            mp[ch]--;
        }

        for(auto &p: mp){
            if(p.second>0){
                return false;
            }
        }
        return true;
    }
};