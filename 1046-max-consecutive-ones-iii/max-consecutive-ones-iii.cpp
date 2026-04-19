class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxLength = 0;
        int countZeros=0;

        int l=0, r=0;

        while(r<nums.size()){
            if(nums[r]==0){
                countZeros++;
            }
            if(countZeros>k){
                if(nums[l]==0){
                    countZeros--;
                }
                l++; 
            }
            maxLength = max(maxLength,r-l+1);
            r++;
        }

        // for(int l=0; l<nums.size(); l++){
        //     countZeros = 0;
        //     for(int r=l; r<nums.size(); r++){
        //         if(nums[r]==0){
        //             countZeros++;
        //         }
        //         if(countZeros>k) break;
        //         maxLength = max(maxLength,r-l+1);
        //     }
        // }

        return maxLength;
    }
};