#define pii pair<int,int>
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int fresh = 0;

        int minutes=0;

        vector<vector<bool>> vis(m,vector<bool>(n,false));
        queue<vector<int>> q;


        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++){
                if(grid[i][j]==2){
                    vis[i][j] = 1;
                    q.push({i,j,0});
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }

        while(!q.empty()){

            auto info = q.front(); 
            q.pop();

            int r = info[0];
            int c = info[1];
            int time = info[2];

            minutes = max(minutes,time);
            
            if(r-1>=0 && !vis[r-1][c] && grid[r-1][c]==1){ vis[r-1][c] = true; q.push({r-1,c,time+1}); fresh--;}
            if(r+1<grid.size() && !vis[r+1][c]  && grid[r+1][c]==1){ vis[r+1][c] = true;q.push({r+1,c,time+1}); fresh--;} 
            if(c+1<grid[0].size() && !vis[r][c+1] &&  grid[r][c+1]==1){ vis[r][c+1] = true;q.push({r,c+1,time+1}); fresh--;} 
            if(c-1>=0 && !vis[r][c-1] && grid[r][c-1]==1){ vis[r][c-1] = true;q.push({r,c-1,time+1}); fresh--;} 
      
        }

        if(fresh>0) return -1;


        return minutes;
    }
};