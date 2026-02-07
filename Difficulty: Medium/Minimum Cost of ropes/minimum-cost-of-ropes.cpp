#include <algorithm>
class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        int minCost=0;
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(int i:arr){
            pq.push(i);
        }
        for(int i=1; i<arr.size(); i++){
            int r1 = pq.top(); pq.pop();
            int r2 = pq.top(); pq.pop();
            pq.push(r1+r2);
            minCost+=r1+r2;
        }
        return minCost;
    }
};