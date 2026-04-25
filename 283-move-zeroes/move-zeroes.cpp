class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> temp(nums.size(),0);

        int idx=0;

        for(int i:nums){
            if(i){
                temp[idx++] = i;
            }   
        }

        for(int i=0; i<nums.size(); i++){
            nums[i]=temp[i]; 
        }
    }
};