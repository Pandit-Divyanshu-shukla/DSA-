class Solution {
public:
    // int ways(int n, vector<int> &dp){
    //     if(n==0 || n==1) return 1;

    //     if(dp[n]!=-1) return dp[n];
    //     return dp[n] = ways(n-1,dp) + ways(n-2,dp);
    // }
    int climbStairs(int n) {
        if(n==0 || n==1) return 1;

        vector<int> ways(n+1,-1);
        ways[0] = ways[1] = 1;

        for(int i=2; i<=n; i++){
            ways[i] = ways[i-1] + ways[i-2];
        }
        return ways[n];
    }
};