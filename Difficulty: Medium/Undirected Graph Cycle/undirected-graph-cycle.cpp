class Solution {
  public:
    bool dfs(int u, vector<bool> &vis,vector<vector<int>> &adj, int par){
        vis[u] = true;
        
        for(int v: adj[u]){
            if(!vis[v]){
                if(dfs(v,vis,adj,u)){
                    return true;
                }
            }
            else if(par != v){
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        vector<bool> vis(V,false);
        for(auto &e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        int src = 0;
        bool isCycle;
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(dfs(i,vis,adj,-1)) return true;
            }
        }
        
        return false;
    }
};