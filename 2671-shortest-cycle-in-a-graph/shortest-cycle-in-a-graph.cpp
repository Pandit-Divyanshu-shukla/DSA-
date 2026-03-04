#define pii pair<int,int>
class Solution {
public:
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

            if(!visited[src]){
                queue<pii> q;
                q.push({src,-1});
                visited[src] = true;
                
                while(!q.empty()){

                    int node = q.front().first;
                    int par = q.front().second;

                    q.pop();
                    for(int v: adj[node]){

                        if(!visited[v]){
                            depth[v] = depth[node] + 1;
                            q.push({v,node});
                            visited[v] = true;
                        }else if(v!=par){
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