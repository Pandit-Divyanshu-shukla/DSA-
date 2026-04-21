class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt=0;
        unordered_map<char,int> mp;

        int l=0, r=0;

        while(r<s.length()){
            mp[s[r]]++;
            while(mp['a']>=1 && mp['b']>=1 && mp['c']>=1){
                cnt+=s.length()-r;
                mp[s[l]]--;
                l++;
            }
            r+=1;
        }

        
        return cnt;
    }
};