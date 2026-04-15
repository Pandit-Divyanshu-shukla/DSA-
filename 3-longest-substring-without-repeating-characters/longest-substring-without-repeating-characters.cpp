class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int n = s.length();

        if(n<=1) return n;

        int ans=INT_MIN;

        string sub;
        int l=0, r=0;

        while(r<n){
            char ch = s[r];
            if(mp.count(ch) && l<=mp[ch]){
                l = mp[ch]+1;
                mp[ch] = r;
            }else{
                mp[ch] = r;
                ans = max(ans,r-l+1);
            }
            r = r+1;
        }

        
        return ans;

    }
};