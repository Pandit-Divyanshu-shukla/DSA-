class Solution {
  public:
    int lcs(string& s1, string& s2, int i, int j, int&ans, vector<vector<int>> &dp){
        if(i==0 || j==0) return 0;
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        lcs(s1,s2,i-1,j,ans,dp);
        lcs(s1,s2,i,j-1,ans,dp);
        
        if(s1[i-1]==s2[j-1]){
            dp[i][j] =  1  + lcs(s1,s2,i-1,j-1,ans,dp);
        }else{
            dp[i][j] = 0;
            
        }
        
        ans = max(ans,dp[i][j]);
        return dp[i][j];
    }
    int longCommSubstr(string& s1, string& s2) {
        // your code here
        
        int l1 = s1.length();
        int l2 = s2.length();
        vector<vector<int>> dp(l1+1,vector<int>(l2+1,-1));
        int ans = 0;
        lcs(s1,s2,l1,l2,ans,dp);
        return ans;
    }
};