class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> sq;
        for(int i=0; i<nums.size(); i++){
            sq.push_back(nums[i]*nums[i]);
        }

        int st=0, end = nums.size()-1;
        int k = end;

        while(st<=end){
            if(sq[st]<=sq[end]){
                nums[k--] = sq[end--];
            }else{
                nums[k--] = sq[st++];
            }
        }

        // sort(nums.begin(), nums.end());

        return nums;
    }
};