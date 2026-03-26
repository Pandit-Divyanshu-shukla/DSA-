class Solution {
public:
    int solve(string &t1, string &t2, int len1, int len2,vector<vector<int>> &dp){

        if(len1==0 || len2==0){
            return 0;
        }
        
        if(dp[len1][len2]!=-1) return dp[len1][len2];

        if(t1[len1-1] == t2[len2-1]){
            return dp[len1][len2] = 1 + solve(t1,t2,len1-1,len2-1,dp);
        }else{
            return dp[len1][len2] = max(
                solve(t1,t2,len1-1,len2,dp),
                solve(t1,t2,len1,len2-1,dp)
                );
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.size();
        int len2 = text2.size();
        vector<vector<int>> dp(len1+1,(vector<int>(len2+1,-1)));
        return solve(text1, text2, len1,len2,dp);
    }
};