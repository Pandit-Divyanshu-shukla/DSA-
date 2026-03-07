class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n,false);

        vector<vector<int>> adj(n);

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i!=j && isConnected[i][j]){
                    adj[i].push_back(j);
                }
            }
        }

        int cnt = 0;

        for(int i=0; i<n; i++){
            if(!vis[i]){
                cnt++;
                queue<int> q;
                q.push(i);
                vis[i]=true;

                while(!q.empty()){
                    int node = q.front(); q.pop();
                    for(int v: adj[node]){
                        if(!vis[v]){
                            vis[v] = true;
                            q.push(v);
                        }
                    }
                }
            }
        }

        return cnt;
    }
};