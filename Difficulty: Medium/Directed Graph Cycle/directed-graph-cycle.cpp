class Solution {
  public:
    bool dfs(int src, vector<bool> &vis, vector<bool> &recP, vector<vector<int>> &adj){
        vis[src] = true;
        recP[src] = true;
        
        for(int v:adj[src]){
            if(!vis[v] && dfs(v,vis,recP,adj)) return true;
            else if(recP[v]) return true;
        }
        
        //backtrack
        recP[src] = false;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        int n = V;
        vector<vector<int>> adj(n);
  
      vector<bool> vis(n,false);
      vector<bool> recP(n,false);
      for(auto &e : edges){
        adj[e[0]].push_back(e[1]);
      }
    
    
      for(int i=0; i<V; i++){
        if(!vis[i]){
          if(dfs(i,vis,recP,adj)) return true;
        }
      }
      return false;
    }
};