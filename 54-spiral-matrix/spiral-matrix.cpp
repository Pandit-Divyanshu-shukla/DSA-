class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int sr = 0, sc=0;
        int er = matrix.size()-1, ec = matrix[0].size()-1;

        vector<int> res;
        while(sr<=er && sc<=ec){
            //Right
            for(int i=sc; i<=ec; i++){
                res.push_back(matrix[sr][i]);
            }

            //Down
            for(int i=sr+1; i<=er; i++){
                res.push_back(matrix[i][ec]);
            }

            //Left
            for(int i=ec-1; i>=sc; i--){
                if(sr==er) break;
                res.push_back(matrix[er][i]);
            }

            //Up
            for(int i=er-1; i>sr; i--){
                if(sc==ec) break;
                res.push_back(matrix[i][sc]);
            }

            sr++; sc++;
            er--; ec--;
        }

        return res;

    }
};