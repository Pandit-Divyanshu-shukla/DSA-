class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>> &visited){
        // Checking Range 
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()) return false;

        if(visited[i][j]) return true;

        visited[i][j] = true;

        if(grid[i][j]==1) return true;
        
        int up = dfs(grid,i-1,j,visited);
        int down = dfs(grid,i+1,j,visited);
        int left = dfs(grid,i,j-1,visited);
        int right = dfs(grid,i,j+1,visited);

        if(left && right && up && down){ return true;}

        return false;

    }
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int closedIslands = 0;

        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j] && grid[i][j]==0){
                    if(dfs(grid,i,j,visited)){
                        closedIslands++;
                    }
                }
            }
        }

        return closedIslands;
    }
};