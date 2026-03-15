int missingNumber(int* nums, int numsSize) {
    
    int *count = (int*) calloc(numsSize+1,sizeof(int));

    int ans = -1;

    for(int i=0; i<numsSize; i++){
        count[nums[i]]++;
    }

    for(int i=0; i<=numsSize; i++){
        if(!count[i]){
            ans= i;
        }
    }

    return ans;

}