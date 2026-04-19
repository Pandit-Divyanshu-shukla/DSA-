class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int l=0, r=0;
        unordered_map<char,int> mp;
        
        int maxLen=INT_MIN;
        
        while(r<s.size()){
            mp[s[r]]++;
            while(mp.size()>k){
                mp[s[l]]--;
                if(mp[s[l]]==0){
                    mp.erase(s[l]);
                }
                l++;
            }
            maxLen = max(maxLen,r-l+1);
            r++;
            
        }
        
        if(mp.size()!=k){
            return -1;
        }
        
        return maxLen;
    }
};