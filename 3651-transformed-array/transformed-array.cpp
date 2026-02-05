class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int> result;
        int n = nums.size();

        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0){
                result.push_back(nums[i]);
            }else{
                if(nums[i]>0){
                    int idx = (i+nums[i])%n;
                    result.push_back(nums[idx]);
                    cout<<result[i]<<" ";
                }
                else{
                    int idx = ((i+nums[i])%n + n )%n;
                    result.push_back(nums[idx]);
                    cout<<result[i]<<" ";
                }
            }
        }
        return result;
    }
};