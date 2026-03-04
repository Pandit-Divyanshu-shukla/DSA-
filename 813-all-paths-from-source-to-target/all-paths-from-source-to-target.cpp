class Solution {
public:
    
    void dfs(int src,vector<vector<int>>& graph, vector<bool>& visited,vector<vector<int>>& ans, vector<int>&currPath, int dest){

        visited[src] = true;
        currPath.push_back(src);
        
        for(int v: graph[src]){
            if(!visited[v]){
                dfs(v,graph,visited,ans,currPath,dest);
            }
        }
        if(src==dest){
            ans.push_back(currPath);
        }

        visited[src] = false;
        currPath.pop_back();

    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        int n = graph.size();
        vector<int> currPath;
        vector<bool> visited(n,false);
        int src = 0;
        dfs(src,graph,visited,ans,currPath,n-1);
        return ans;
    }
};