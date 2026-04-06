class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prevMin = INT_MAX;
        int maxProfit = 0;

        for(int i=1; i<prices.size(); i++){
            int bestCurrBuyPrice = min(prevMin,prices[i-1]);
            prevMin = bestCurrBuyPrice;
            maxProfit = max(maxProfit, prices[i]-bestCurrBuyPrice);
        }

        return maxProfit;
    }
};