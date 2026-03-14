int singleNumber(int* nums, int numsSize) {

    int ans = 0;
    
    for(int i=0; i<32; i++){
        int count1 = 0;
        for(int j=0; j<numsSize; j++){
            if(nums[j] & 1) count1++;
            nums[j]=nums[j]>>1;
        }
        if(count1 % 3 != 0) ans = ans | (1U<<i);
    }

    return ans;
}