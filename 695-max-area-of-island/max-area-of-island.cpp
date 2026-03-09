class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>> &visited, int &currCmpArea){
        // Checking Range 
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || visited[i][j] || grid[i][j]==0) return;
        ++currCmpArea;

        visited[i][j] = true;

        dfs(grid,i+1,j,visited,currCmpArea);
        dfs(grid,i,j-1,visited,currCmpArea);
        dfs(grid,i-1,j,visited,currCmpArea);
        dfs(grid,i,j+1,visited,currCmpArea);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // if(grid.size()==0){ return 0;}

        int m = grid.size();
        int n = grid[0].size();

        int maxArea = 0;

        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j] && grid[i][j]==1){
                    int currCmpArea = 0;
                    // maxArea++;
                    dfs(grid,i,j,visited,currCmpArea);
                    maxArea = max(currCmpArea, maxArea);
                }
            }
        }

        return maxArea;
    }
};