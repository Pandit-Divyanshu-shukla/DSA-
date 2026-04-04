class Solution {
public:
    int unique(int n, vector<int> &dp){
        if(n==0 || n==1) return 1;

        if(dp[n]!=-1) return dp[n];

        int cntTrees = 0;
        for(int i=0; i<n; i++){
            cntTrees+=unique(i,dp)*unique(n-i-1,dp);
        }

        return dp[n]=cntTrees;
    }
    int numTrees(int n) {
        vector<int> dp(n+1,-1);
        return unique(n,dp);
    }
};