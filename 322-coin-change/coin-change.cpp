class Solution {
public:
    int mincoins(vector<int> &coins, int A, int c){
    vector<vector<int>> dp(c+1,vector<int>(A+1,INT_MAX));

    for(int i=0; i<=c; i++){
        dp[i][0] = 0;
    }


    for(int i=1; i<=c; i++){
        for(int j=1; j<=A; j++){
            int coin = coins[i-1];
            if(coin<=j && dp[i][j-coin]!=INT_MAX){
                int exclude = dp[i-1][j];
                int include = dp[i][j-coin];
                dp[i][j] = min(exclude,1+include);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }


    return dp[c][A];
}
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        return mincoins(coins,amount,n)==INT_MAX ? -1 : mincoins(coins,amount,n);
    }
    
};