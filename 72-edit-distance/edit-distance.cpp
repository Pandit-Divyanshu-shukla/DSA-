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
            int insertOp = solve(w1,w2,i,j-1,dp);
            int deleteOp = solve(w1,w2,i-1,j,dp);
            int replaceOp = solve(w1,w2,i-1,j-1,dp);
            return dp[i][j] = 1 + min({insertOp,deleteOp,replaceOp});
        }

    }
    int minDistance(string word1, string word2) {
        int l1 = word1.size();
        int l2 = word2.size();

        vector<vector<int>> dp(l1+1,vector<int>(l2+1,0));

        for(int i=0; i<=l1; i++){
            dp[i][0] = i;
        }
        for(int j=0; j<=l2; j++){
            dp[0][j] = j;
        }

        for(int i=1; i<=l1; i++){
            for(int j=1; j<=l2; j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    int insertOp = dp[i][j-1];
                    int deleteOp = dp[i-1][j];
                    int replaceOp = dp[i-1][j-1];
                    dp[i][j] = 1+min({insertOp,deleteOp,replaceOp});
                }
            }
        }

        return dp[l1][l2];
    }
};