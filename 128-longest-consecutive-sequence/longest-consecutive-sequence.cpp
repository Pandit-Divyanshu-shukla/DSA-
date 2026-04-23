class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        sort(nums.begin(),nums.end());
        int cnt=1;
        int longest=1;
        for(int i=1; i<nums.size(); i++){
            if(abs(nums[i]-nums[i-1])==1){
                cnt++;
            }
            else if(nums[i]==nums[i-1]){
                continue;
            }
            else{
                longest = max(longest,cnt);
                cnt=1;
            }
        }
        return max(longest,cnt);
    }
};