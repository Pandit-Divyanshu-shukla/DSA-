class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.length();
        if(n==1) return 1;
        unordered_map<char,int> mp;
        int maxLength = 0;

        int l=0, r=0;

        while(r<n){
            if(mp.count(s[r]) && mp[s[r]]>=l){
                l = mp[s[r]]+1;
                mp[s[r]] = r;
                // maxLength = max(maxLength,r-l+1);
            }else{
                mp[s[r]] = r;
                maxLength = max(maxLength,r-l+1);
            }
            r+=1;
        }

        return maxLength;
        
    }
};