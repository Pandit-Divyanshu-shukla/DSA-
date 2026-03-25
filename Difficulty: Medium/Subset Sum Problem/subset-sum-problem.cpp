class Solution {
  public:
    bool solve(vector<int>& arr, int sum, int n, vector<vector<int>> &dp){
        // if(sum == 0 && n==0) return true;
        if(sum==0) return true;
        if(n==0) return false;
        
        int currEle = arr[n-1];
        if(dp[n-1][sum]!=-1) return dp[n-1][sum];
        
        if(currEle <= sum){
            // Add to subset
            bool ans1 = solve(arr,sum-currEle, n-1, dp);
            
            // Don't add to subset
            bool ans2 = solve(arr,sum, n-1, dp);
            
            return dp[n-1][sum] = (ans1 || ans2);
        }
        else{
            return dp[n-1][sum]=solve(arr,sum, n-1, dp);
        }
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        return solve(arr,sum, n, dp);
    }
};