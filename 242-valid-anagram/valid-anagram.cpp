#include <string>
class Solution {
public:
    bool isAnagram(string s, string t) {
       unordered_map<char,int> mp;

       if(s.length()!=t.length()){
        return false;
       }
       for(char ch: s){
            if(!mp.count(ch)){
                mp[ch] = 1;
                continue;
            }
            mp[ch]++;
       }
       for(char ch: t){
            if(!mp.count(ch)){
                return false;
            }
            mp[ch]--;
       }
       
       for(pair<char,int>p:mp){
        if(p.second){
            return false;
        }
       }
       return true;

    }
};