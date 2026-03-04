class Solution {
public:
    bool chkRow(int row, vector<vector<int>>& mat){
        int count=0;
        for(int itr=0; itr<mat[0].size(); itr++){
            if(mat[row][itr]==1){
                count++;
            }
        }
        if(count>1){
            return false;
        }
        return true;
    }
    bool chkCol(int col, vector<vector<int>>& mat){
        int count=0;
        for(int itr=0; itr<mat.size(); itr++){
            if(mat[itr][col]==1){
                count++;
            }
        }
        if(count>1){
            return false;
        }
        return true;
    }
    int numSpecial(vector<vector<int>>& mat) {
        int special = 0;
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[0].size(); j++){
                if(mat[i][j]==1 && chkRow(i,mat) && chkCol(j,mat)){
                    special++;
                }
            }
        }
        return special;
    }
};