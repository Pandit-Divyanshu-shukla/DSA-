class Solution {
  public:
    int solve(int W, vector<int> &val, vector<int> &wt, int n,vector<vector<int>> &dp){
        if(W==0 || n==0) return 0;
        
        if(dp[n-1][W]!=-1) return dp[n-1][W];
        
        int itemWt = wt[n-1];
        int itemVal = val[n-1];
        
        if(itemWt<=W){
            // Include
            int left = solve(W-itemWt,val,wt,n-1,dp) + itemVal;
            //Exclude
            int right = solve(W,val,wt,n-1,dp);
            
            return dp[n-1][W] = max(left,right);
        }
        else{
            // exclude
            return dp[n-1][W] = solve(W,val,wt,n-1,dp);
        }
        
        
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = wt.size();
        vector<vector<int>> dp(n+1,vector<int>(W+1,-1));
        return solve(W,val,wt,wt.size(),dp);
        
    }
};