class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l=0, r=0;
        int maxOnes = 0;

        while(r<nums.size()){
            if(nums[r]){
                maxOnes = max(maxOnes,r-l+1);
            }
            else{
                l = r+1;
            }
            r = r+1;
        }

        return maxOnes;
    }
};