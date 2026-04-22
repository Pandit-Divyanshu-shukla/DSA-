class Solution {
public:
    int sumAtMostK(vector<int>& nums, int goal){
        if(goal<0) return 0;
        int n = nums.size();
        int cnt=0;

        int l=0, r=0;
        long long sum=0;

        while(r<n){
            sum+=nums[r];
            while(sum>goal){
                sum-=nums[l];
                l++;
            }
            cnt+=r-l+1;
            r++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        int ans = sumAtMostK(nums,goal) - sumAtMostK(nums,goal-1);

        // for(int i=0; i<n; i++){
        //     int sum = 0;
        //     for(int j=i; j<n; j++){
        //         sum+=nums[j];
        //         if(sum==goal){
        //             cnt++;
        //         }
        //     }
        // }

        return ans;
    }
};