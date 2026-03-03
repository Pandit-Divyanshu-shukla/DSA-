class Solution {
public:
    bool dfs(int u, vector<bool> &visited, int n, vector<list<int>>& edges, int destination){
        if(u==destination){
            return true;
        }
        visited[u] = true;
        for(int v: edges[u]){
            if(!visited[v]){
                visited[v] = true;
                if (dfs(v,visited,n,edges,destination)) return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool> visited(n,false);
        visited[source] = true;
        vector<list<int>> adj(n);

        for(auto &edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        return dfs(source,visited,n,adj,destination);
    }
};