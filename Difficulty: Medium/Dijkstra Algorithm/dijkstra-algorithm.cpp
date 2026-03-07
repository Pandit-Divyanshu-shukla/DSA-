#define pii pair<int,int>
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<int> dist(V,INT_MAX);
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        
        dist[src] = 0;
        pq.push({0,src});
        
        vector<vector<pii>> adj(V);
        for(auto &e: edges){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        
        while(!pq.empty()){
            int node = pq.top().second;
            int currD = pq.top().first;
            
            pq.pop();
            
            if(currD > dist[node]) continue;
            
            for(auto &p: adj[node]){
                int v = p.first;
                int wt = p.second;
                if(dist[v]>dist[node]+wt){
                    dist[v] = dist[node]+wt;
                    pq.push({dist[v],v});
                }
            }
        }
        
        return dist;
    }
};