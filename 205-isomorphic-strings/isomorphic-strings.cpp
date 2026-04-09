class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()) return false;

        unordered_map<char,char> mp;
        unordered_map<char,char> map;

        for(int i=0; i<s.length(); i++){
            if(mp.count(s[i])!=0 && mp[s[i]]!=t[i]){
                return false;
            }
            if(map.count(t[i])!=0 && map[t[i]]!=s[i]){
                return false;
            }
            
            map[t[i]] = s[i];
            mp[s[i]] = t[i];
        }

        return true;
    }
};