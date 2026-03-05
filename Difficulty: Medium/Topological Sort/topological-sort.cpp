class Solution {
  public:
    void dfs(int src, vector<bool> &vis, stack<int> &st, vector<vector<int>> &edges){
        vis[src] = true;
        for(int v: edges[src]){
            if(!vis[v]){
                dfs(v,vis,st,edges);
            }
        }
        st.push(src);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        vector<int> ans;
        vector<bool> vis(V,false);
        stack <int> st;
        for(auto &e: edges){
            adj[e[0]].push_back(e[1]);
            // adj[e[1]].push_back(e[0]);
        }
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i,vis,st,adj);
            }
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
        
    }
};