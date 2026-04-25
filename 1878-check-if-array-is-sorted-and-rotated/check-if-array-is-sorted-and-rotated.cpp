class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int cnt=0;
        for(int i=1; i<2*nums.size(); i++){
            if(nums[i%n]<nums[(i-1)%n]) cnt++;
        }
        if(cnt>2) return false;
        return true;
    }
};