class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> inDegree(V,0);
        vector<bool> vis(V,false);
        
        vector<int> ans;
        vector<vector<int>> adj(V);
        
        for(auto &e: edges){
            inDegree[e[1]]++;
            adj[e[0]].push_back(e[1]);
            // adj[e[0]].push_back(e[1]);
        }
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                queue<int> q;
                for(int i=0; i<V; i++){
                    if(!inDegree[i]) q.push(i);
                }
                
                while(!q.empty()){
                    int node = q.front(); q.pop();
                    ans.push_back(node);
                    vis[node] = true;
                    for(int v: adj[node]){
                        inDegree[v]--;
                        if(!vis[v] && !inDegree[v]){
                            q.push(v);
                        }
                        
                    }
                }
                
            }
        }
        return ans;
    }
};