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

            int dr[4] = {-1,1,0,0};
            int dc[4] = {0,0,-1,1};

            for(int k=0; k<4; k++){
                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && grid[nr][nc]==1){
                    vis[nr][nc] = true;
                    q.push({nr,nc,time+1});
                    fresh--;
                }
            }
      
        }

        if(fresh>0) return -1;


        return minutes;
    }
};