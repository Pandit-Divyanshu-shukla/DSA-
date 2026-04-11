class Solution {
public:
    void dfs(vector<vector<int>>& image,int r,int st, int c, int color,vector<vector<bool>> &vis){
        if(r<0 || c<0 || r>=image.size() || c>=image[0].size() || image[r][c]!=st || vis[r][c]){
            return;
        }

        image[r][c] = color;
        vis[r][c] = true;

        dfs(image,r+1,st,c,color,vis);
        dfs(image,r,st,c+1,color,vis);
        dfs(image,r,st,c-1,color,vis);
        dfs(image,r-1,st,c,color,vis);

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        dfs(image,sr,image[sr][sc],sc,color,vis);
        return image;
    }
};