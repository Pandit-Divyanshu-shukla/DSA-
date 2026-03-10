class Solution {
public:
    void dfs(int r, int c, int st, int color, vector<vector<bool>> &visited,vector<vector<int>>& image){
        if(r<0 || c<0 || r>=image.size() || c>=image[0].size() || image[r][c]!=st || visited[r][c]) return;

        visited[r][c] = true;
        image[r][c] = color;

        dfs(r,c+1,st,color,visited,image);
        dfs(r,c-1,st,color,visited,image);
        dfs(r+1,c,st,color,visited,image);
        dfs(r-1,c,st,color,visited,image);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(); 
        int n = image[0].size();

        int st = image[sr][sc];

        vector<vector<bool>> visited(m,vector<bool>(n,false));

        dfs(sr,sc,st,color,visited,image);

        return image;
    }
};