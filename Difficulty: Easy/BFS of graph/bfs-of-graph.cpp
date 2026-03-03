class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        queue<int> q;
        vector<bool> visited(adj.size(),false);
        
        vector<int> BFS;
        int src = 0;
    
        visited[src] = true;
        q.push(src);
        
        while(!q.empty()){
            
            int node = q.front();
            BFS.push_back(node);
            q.pop();
            
            for(int v: adj[node]){
                
                if(!visited[v]){
                    
                    visited[v] = true;
                    q.push(v);
                    
                }
            }
            
        }
        return BFS;
    }
};