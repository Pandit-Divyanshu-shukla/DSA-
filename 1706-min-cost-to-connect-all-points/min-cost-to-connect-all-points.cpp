#define vi vector<int>
#define pii pair<int,int>
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<bool> mstSet(n,false);
        int src = 0;

        priority_queue<vi,vector<vi>, greater<vi>> pq;
        pq.push({0,src});

        int ans = 0;

        while(!pq.empty()){
            auto top = pq.top(); pq.pop();

            int wt = top[0];
            int node = top[1];

            if(!mstSet[node]){ 

                mstSet[node] = true;
                ans+= wt;

                for(int v=0; v<n; v++){
                    if(node!=v && !mstSet[v]){  // u->v
                        int weight = abs(points[node][0]-points[v][0]) + abs(points[node][1]-points[v][1]);
                        pq.push({weight,v});
                    }
                }
            }
        }
        return ans;
    }
};