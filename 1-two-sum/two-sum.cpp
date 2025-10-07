class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        vector<int> ans(2,0);
        
        for(int i=0; i<nums.size(); i++){
            int complement = target - nums[i];
            if(mp.count(complement)){
                return {mp[complement],i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};