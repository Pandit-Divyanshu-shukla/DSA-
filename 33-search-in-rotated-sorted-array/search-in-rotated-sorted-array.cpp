class Solution {
public:
    int search(vector<int>& nums, int target) {
        for(int idx=0; idx<nums.size(); idx++){
            if(nums[idx]==target) return idx;
        }
        return -1;
    }
};