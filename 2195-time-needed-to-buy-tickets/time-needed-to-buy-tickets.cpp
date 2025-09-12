class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> q;
        int tno = tickets.size();
        
        int tickets2Buy = tickets[k];
        int timeNeeded = 0;
        

        for(int idx=0; idx<tno; idx++){
            int curr = tickets[idx];
            if(idx<=k){
                timeNeeded+=min(tickets2Buy,curr);
            }
            else{
                timeNeeded+=min(curr,tickets2Buy-1);
            }
        }

        return timeNeeded;
    }
};