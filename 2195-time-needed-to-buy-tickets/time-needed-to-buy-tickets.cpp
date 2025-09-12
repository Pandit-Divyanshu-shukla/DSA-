class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> q;
        int tno = tickets.size();
        for(int idx=0; idx<tno; idx++){
            q.push(idx);
        }

        int timeNeeded = 0;
        while(!q.empty()){
            timeNeeded++;
            int front = q.front();
            q.pop();
            tickets[front]--;
            if(tickets[front]>0) q.push(front);
            if(tickets[k]==0) return timeNeeded;
        }
        return timeNeeded;
    }
};