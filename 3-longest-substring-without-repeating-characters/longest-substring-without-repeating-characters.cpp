class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n==0) return 0;

        int l=0, r=0;
        unordered_map<char,int> mp;

        int maxLen = INT_MIN;

        while(r<n){
            mp[s[r]]++;
            while(mp[s[r]]>1){
                mp[s[l]]--;
                l++;
            }
            maxLen = max(maxLen,r-l+1);
            r++;
        }
        return maxLen;
    }
};