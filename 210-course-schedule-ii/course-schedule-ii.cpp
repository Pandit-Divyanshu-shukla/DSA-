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
    void dfs_top(int src, vector<bool> &vis,vector<vector<int>> &adj, stack<int> &st){
        vis[src] = true;
        for(int v: adj[src]){
            if(!vis[v]){
                dfs_top(v,vis,adj,st);
            }
        }
        st.push(src);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<bool> recP(V,false);
        vector<bool> vis(V,false);
        vector<vector<int>> adj(V);

        vector<int> ans;
        stack<int>st;

        for(auto &e: prerequisites){
            adj[e[1]].push_back(e[0]);
        }

        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(dfs(i,vis,adj,recP)) return {};   //Can't be finished
            }
        }

        fill(vis.begin(),vis.end(),false);

        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs_top(i,vis,adj,st);
            }
        }

        while(!st.empty()){
            ans.push_back(st.top()); st.pop();
        }

        return ans;

        
    }
};