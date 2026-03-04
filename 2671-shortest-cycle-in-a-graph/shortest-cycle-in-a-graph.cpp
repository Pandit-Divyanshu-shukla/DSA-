class Solution {
public:
    void bfs(int src, vector<bool>& visited, vector<int>&parent, vector<vector<int>> &adj, int &minLen,vector<int> &depth){

        
    }
    int findShortestCycle(int n, vector<vector<int>>& edges) {

        

        vector<vector<int>> adj(n);

        for(auto &e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int minLen = INT_MAX;
        
        for(int src=0; src<n; src++){
            vector<bool>visited(n,false);
            vector<int> depth(n,0);
            vector<int> parent(n,-1);
            if(!visited[src]){
                queue<int> q;
                q.push(src);
                visited[src] = true;
                
                while(!q.empty()){

                    int node = q.front(); q.pop();
                    for(int v: adj[node]){

                        if(!visited[v]){
                            depth[v] = depth[node] + 1;
                            q.push(v);
                            visited[v] = true;
                            parent[v] = node;
                        }else if(v!=parent[node]){
                            // cycle
                            int len = depth[node]+depth[v]+1;  // both distance + 1(off edge)
                            minLen = min(len,minLen);
                        }
                    }
                }
            }
        }

        return minLen==INT_MAX ? -1 : minLen;
    }
};