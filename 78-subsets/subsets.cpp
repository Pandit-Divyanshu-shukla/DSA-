class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int numSubsets = pow(2,nums.size());

        vector<vector<int>> ans;

        for(int i=0; i<numSubsets; i++){
            vector<int> currSubset = {};
            for(int j=0; j<nums.size(); j++){
                int currBit = (i>>j)&1;
                if(currBit){
                    currSubset.push_back(nums[n-j-1]);
                }
            }
            ans.push_back(currSubset);
        }

        return ans;
    }
};