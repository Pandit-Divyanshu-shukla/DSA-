#define pii pair<int,int>
class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<bool> mstSet(V,false);
        int ans=0;
        
        vector<vector<pii>> adj(V);
        
        // build adjacency list
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        //"wt,v}"
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        int src=0;
        // mstSet[src] = true;
        
        pq.push({0,src});
        
        while(!pq.empty()){
            auto [wt,v] = pq.top();
            pq.pop();
            
            if(!mstSet[v]){
                mstSet[v]=true;
                ans+=wt;
                for(auto &n: adj[v]){
                    pq.push({n.second,n.first});
                }
            }
        }
        return ans;
    }
};