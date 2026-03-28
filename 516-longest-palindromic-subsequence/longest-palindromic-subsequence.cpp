class Solution {
public:
    int LCS(string &s1, string &s2, int l1, int l2,vector<vector<int>> &dp){
        if(l1==0 || l2==0){
            return 0;
        }

        if(dp[l1][l2]!=-1) return dp[l1][l2];

        if(s1[l1-1]==s2[l2-1]){
            // matches
            return dp[l1][l2] =  1 + LCS(s1,s2,l1-1,l2-1,dp);
        }else{
            return dp[l1][l2] = max(LCS(s1,s2,l1-1,l2,dp),LCS(s1,s2,l1,l2-1,dp));
        }
    }
    int longestPalindromeSubseq(string s) {
        string s1 = s;
        string s2 = s;
        reverse(s2.begin(),s2.end());

        int l1 = s1.length();
        int l2 = s2.length();

        vector<vector<int>> dp(l1+1,vector<int>(l2+1,-1));

        return LCS(s1,s2,l1,l2,dp);
    }
};