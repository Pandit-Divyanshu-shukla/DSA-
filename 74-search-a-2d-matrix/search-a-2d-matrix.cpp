class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rSize = matrix.size();
        int cSize = matrix[0].size();
        int row=0, col = cSize-1;

        while(row!=rSize && col!=-1){
            int currVal = matrix[row][col];
            if(currVal==target){
                return true;
            }

            if(target>currVal){
                row++;
            }else{{
                col--;
            }}
        }
        return false;
    }
    
};