class Solution {
  public:
    void dfs(int u, vector<bool> &vis, vector<vector<int>> &adj,vector<int> &component ){
        vis[u] = true;
        component.push_back(u);
        for(int v: adj[u]){
            if(!vis[v]){
                dfs(v,vis,adj,component);
            }
        }
    }
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        vector<vector<int>> cmp;
        
        
        for(auto &e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        vector<bool> vis(V, false);
        for(int i=0; i<V; i++){
            
            if(!vis[i]){
                vector<int> component;
                dfs(i,vis,adj,component);
                cmp.push_back(component);
            }
        }
        
        return cmp;
        
    }
};
