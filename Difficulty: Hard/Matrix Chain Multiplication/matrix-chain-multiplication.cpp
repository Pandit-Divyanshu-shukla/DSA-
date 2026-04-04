class Solution {
  public:
    int mcm(vector<int> &arr, int st, int end, vector<vector<int>> &dp){
        if(st==end) return 0;
        
        int ans = INT_MAX;
        if(dp[st][end]!=-1) return dp[st][end];
        
        for(int i=st; i<end; i++){
            int leftPartCost = mcm(arr,st,i,dp);
            int rightPartCost = mcm(arr,i+1,end,dp);
            
            int costToMulLR = arr[st-1]*arr[i]*arr[end];
            
            int totalCurrCost = leftPartCost + rightPartCost + costToMulLR;
            ans = min(ans,totalCurrCost);
        }
        
        return dp[st][end] = ans;
    }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        vector<vector<int>> dp(arr.size()+1,vector<int> (arr.size()+1,-1));
        return mcm(arr,1,arr.size()-1,dp);
    }
};