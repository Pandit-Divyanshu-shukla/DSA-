class Solution {
public:
    
    void dfs(vector<vector<bool>> &vis, int i, int j,vector<vector<char>>& grid){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size()) return;

        if(vis[i][j] || grid[i][j]=='0') return;

        vis[i][j] = true;
        
        dfs(vis,i,j+1,grid);
        dfs(vis,i+1,j,grid);
        dfs(vis,i,j-1,grid);
        dfs(vis,i-1,j,grid);
        
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m,vector<bool>(n,false));
        int islands = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    dfs(visited,i,j,grid);
                    islands++;
                }
            }
        }

        return islands;
    }
};