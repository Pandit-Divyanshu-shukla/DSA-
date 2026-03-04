class Solution {
public:

    void dfs(int src, vector<bool> &visited,vector<int> &depth, vector<int> &adj, vector<bool> &recP, int &maxLen){
        visited[src] = true;
        recP[src] = true;
        int neighbour = adj[src];
        if(neighbour==-1){
            recP[src]=false;
            return;
        }
        if(!visited[neighbour]){
                depth[neighbour] = depth[src] + 1;
                dfs(neighbour,visited,depth,adj,recP,maxLen);
            }
        else if(recP[neighbour]){
                //cycle
                maxLen = max(maxLen,depth[src]-depth[neighbour]+1);
            }
        
        recP[src] = false;
    }
    int longestCycle(vector<int>& edges) {

        int n = edges.size();

        vector<int> depth(n,0);
        vector<bool> visited(n,false);
        vector<bool> recP(n,false);


        int maxLen = INT_MIN;
    
        for(int i=0; i<edges.size(); i++){
            if(!visited[i]){
                depth[i]=0;
                dfs(i,visited,depth,edges,recP,maxLen);
            }
        }
        return maxLen==INT_MIN ? -1 : maxLen;
    }
};