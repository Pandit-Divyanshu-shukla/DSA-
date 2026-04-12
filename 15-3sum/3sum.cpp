class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0; i<nums.size(); i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int target = -nums[i];

            int st=i+1, end = nums.size()-1;

            while(st<end){
                if(target==nums[st]+nums[end]){
                    ans.push_back({-target,nums[st],nums[end]});
                    while(st<end && nums[st]==nums[st+1]){
                        st++;
                    }
                    while(st<end && nums[end]==nums[end-1]){
                        end--;
                    }
                    st++, end--;
                }
                else if(target>nums[st]+nums[end]){
                    st++;
                }
                else{
                    end--;
                }
            }
        }

        return ans;
    }
};