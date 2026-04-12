class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int>(n));

        int sr=0,sc = 0;
        int er=n-1,ec = n-1;

        int val=1;

        while(sr<=er && sc<=ec){
            // right
            for(int i=sc; i<=ec; i++){
                mat[sr][i] = val;
                val++;
            }

            // down
            for(int i=sr+1; i<=er; i++){
                mat[i][ec] = val;
                val++;
            }
            // left
            for(int i=ec-1; i>=sc; i--){
                if(sr==er)break;
                mat[er][i] = val;
                val++;
            }
            // up
            for(int i=er-1; i>sr; i--){
                if(sc==ec)break;
                mat[i][sc] = val;
                val++;
            }

            sr++; er--;
            sc++; ec--;
            
        }
        return mat;
    }
};