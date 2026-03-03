class Solution {
  public:
  
    void dfs(int u, vector<bool> &visited, vector<int> &ans, vector<vector<int>>& adj){
        visited[u]  = true;
        ans.push_back(u);
        
        for(int neighbour: adj[u]){
            if(!visited[neighbour]){
                dfs(neighbour,visited,ans,adj);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<bool> visited(adj.size(),false);
        
        int src=0;
    
        vector<int> ans;
        dfs(src,visited,ans,adj);
        return ans;
    }
};