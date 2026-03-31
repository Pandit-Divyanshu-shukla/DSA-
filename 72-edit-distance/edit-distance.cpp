class Solution {
public:
    int solve(string &w1, string &w2, int i, int j, vector<vector<int>> &dp){
        if(i==0 || j==0){
            return dp[i][j] = max(i,j);
        }

        if(dp[i][j]!=-1) return dp[i][j];

        if(w1[i-1]==w2[j-1]){
            // matched so move to smaller two problems hor(hors) & ro(ros)
            return dp[i][j] = solve(w1,w2,i-1,j-1,dp);
        }else{
            // one operation + min(insert, delete or replace in string 1)
            return dp[i][j] = 1 + min(solve(w1,w2,i,j-1,dp),min(solve(w1,w2,i-1,j,dp),solve(w1,w2,i-1,j-1,dp)));
        }

    }
    int minDistance(string word1, string word2) {
        int l1 = word1.size();
        int l2 = word2.size();

        vector<vector<int>> dp(l1+1,vector<int>(l2+1,-1));

        return solve(word1,word2,l1,l2,dp);
    }
};