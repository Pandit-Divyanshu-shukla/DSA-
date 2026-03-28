class Solution {
public:
    int solve(int st, int end, string &s,vector<vector<int>> &dp){
        if(st>end){
            return 1;
        }

        if(dp[st][end]!=-1){
            return dp[st][end];
        }

        if(s[st]==s[end]){
            return dp[st][end]=solve(st+1,end-1,s,dp);
        }else{
            return dp[st][end]=0;
        }

        return 1;

    }
    string longestPalindrome(string s) {

        int count=0;
        int maxLen = 0;
        string maxSub="";

        vector<vector<int>> dp(s.length()+1,vector<int>(s.length()+1,-1));

        for(int i=0; i<s.length(); i++){
            for(int j=i; j<s.length(); j++){
                if(solve(i,j,s,dp)){
                    int len = j-i+1;
                    if(len>maxLen){
                        maxSub = s.substr(i,len);
                        maxLen = max(j-i+1,maxLen);
                    }
                }
            }
        }
        return maxSub;
    }
};