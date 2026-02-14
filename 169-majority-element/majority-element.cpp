class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int curr = nums[0];
        int count = 1;
        for(int i=1; i<nums.size(); i++){
            if(!count){
                curr = nums[i];
                count++;
                continue;
            }
            if(nums[i]!=curr){
                count--;
            }else{
                count++;
            }
        }
        return curr;
    }
};