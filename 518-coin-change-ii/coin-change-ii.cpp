
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int A = amount;
        vector<long long> dp(A+1,0);
        const int MOD = 1e9 + 7;

        // one comb thank makes 0 amount is no coins taken
        dp[0] = 1;

        for(int coin:coins){
            for(int i=coin; i<=A; i++){
                if (dp[i] > LLONG_MAX - dp[i - coin]) {
                    dp[i] = LLONG_MAX; // prevent overflow
                } else {
                    dp[i] += dp[i - coin];
                }
            }
            
        }

        return (int)dp[A];
    }
};