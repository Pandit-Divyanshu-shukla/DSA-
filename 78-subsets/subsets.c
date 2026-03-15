/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
        int n = numsSize;
        int numSubsets = 1<<n;

        int **ans = (int**) malloc(numSubsets*sizeof(int*));
        *returnColumnSizes = malloc(numSubsets*sizeof(int));

        *returnSize = numSubsets;

        for(int i=0; i<numSubsets; i++){

            int count=0;

            for(int j=0; j<numsSize; j++){
                int currBit = (i>>j)&1;
                if(currBit){
                    count++;
                }
            }

            (*returnColumnSizes)[i] = count;

            ans[i] = (int*) malloc(count*sizeof(int));

            int k=0;

            for(int j=0; j<numsSize; j++){
                int currBit = (i>>j)&1;
                if(currBit){
                    ans[i][k++] = nums[n-j-1];
                }
            }

        }

        return ans;
}