class Solution {
public:
    int LCS(vector<int> &v1, vector<int> &v2, int l1, int l2, vector<vector<int>> &dp){
        if(l1==0 || l2==0) return 0;

        // Missing:
        if(dp[l1][l2] != -1) return dp[l1][l2];
        
        if(v1[l1-1]==v2[l2-1]){
            return dp[l1][l2] = 1 + LCS(v1,v2,l1-1,l2-1,dp); 
        }else{
            return dp[l1][l2] = max(LCS(v1,v2,l1,l2-1,dp),LCS(v1,v2,l1-1,l2,dp));
        }

    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> v1 = nums;
        set<int> st;
        for(int num: nums){
            st.insert(num);
        }
        vector<int> v2(st.begin(),st.end());

        // sort(st.begin(),st.end());

        int l1 = nums.size();
        int l2= st.size();
        vector<vector<int>> dp(l1+1,vector<int>(l2+1,-1));

        return LCS(v1,v2,l1,l2,dp);
    }
};