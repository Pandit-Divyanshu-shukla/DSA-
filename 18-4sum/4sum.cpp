class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();

        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());

        for(int i=0; i<n; i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            for(int j=i+1; j<n; j++){
                if(j>i+1 && nums[j]==nums[j-1]){
                    continue;
                }

            int st=j+1, end=n-1;
            long long sum = nums[i] + nums[j];
            while(st<end){
                if(target-sum==nums[st]+nums[end]){
                    ans.push_back({nums[i],nums[j],nums[st],nums[end]});
                    st++; end--;

                    while(st<end && nums[st]==nums[st-1]) st++;
                    while(st<end && nums[end]==nums[end+1]) end--;
                }
                else if(nums[st]+nums[end]>target-sum){
                    end--;
                }else{
                    st++;
                }
                
            }
        }
        }

        return ans;
    }
};