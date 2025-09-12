class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = accumulate(gas.begin(), gas.end(), 0);
        int totalCost = accumulate(cost.begin(), cost.end(), 0);

        if(totalGas>=totalCost){
            // solution exists
            int currGas = 0;
            int startid = 0;
            for(int idx=0; idx<gas.size(); idx++){
                currGas+=gas[idx]-cost[idx];
                if(currGas<0){
                    currGas=0;
                    startid = idx+1;
                }
            }
            return startid;
        }
        return -1;
    }
};