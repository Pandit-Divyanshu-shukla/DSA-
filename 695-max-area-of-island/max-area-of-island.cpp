class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>> &visited, int &currCmpArea){

        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==0 || visited[i][j]) return;

        visited[i][j]=1;
        ++currCmpArea;

        dfs(grid,i+1,j,visited,currCmpArea);
        dfs(grid,i-1,j,visited,currCmpArea);
        dfs(grid,i,j+1,visited,currCmpArea);
        dfs(grid,i,j-1,visited,currCmpArea);

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int maxArea = 0;

        vector<vector<bool>> visited(m,vector<bool>(n,0)) ;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int curr=0;
                if(grid[i][j]==1){
                    dfs(grid,i,j,visited,curr);
                    maxArea = max(curr,maxArea);
                }
            }
            
        }

        return maxArea;
    }
};