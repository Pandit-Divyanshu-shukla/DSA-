#define pii pair<int,int>
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        queue<tuple<int,int,int>> q;
        //(u, cost from src, stops)
        q.push({src,0,-1});
        vector<vector<pii>> adj(n);

        for(auto &e : flights){
            adj[e[0]].push_back({e[1], e[2]});
        }

        while(!q.empty()){
            auto [u,cost,stops] = q.front(); q.pop();

            for(auto& v: adj[u]){
                int neighbour = v.first;
                int edgeWeight = v.second;
                if(stops<k && dist[neighbour]>cost+edgeWeight){
                    dist[neighbour]=cost+edgeWeight;
                    q.push({neighbour,dist[neighbour],stops+1});
                }
            }

        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};