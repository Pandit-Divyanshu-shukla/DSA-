class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 0;
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
            if(mp[nums[i]]<=1){
                nums[idx++] = nums[i];
            }
        }

        return idx;
    }
};