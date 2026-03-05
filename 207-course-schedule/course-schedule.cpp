class Solution {
public:
    int dfs(int src, vector<bool> &vis,vector<vector<int>> &adj,vector<bool> &recP){
        vis[src] = true;
        recP[src] = true;
        for(int v: adj[src]){
            if(!vis[v]){
                if(dfs(v,vis,adj,recP)) return true;
            }
            else if(recP[v]) return true;
        }
        recP[src] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<bool> recP(V,false);
        vector<bool> vis(V,false);
        vector<vector<int>> adj(V);

        for(auto &e: prerequisites){
            adj[e[0]].push_back(e[1]);
        }

        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(dfs(i,vis,adj,recP)) return false;   //Can't be finished
            }
        }

        return true;

    }
};