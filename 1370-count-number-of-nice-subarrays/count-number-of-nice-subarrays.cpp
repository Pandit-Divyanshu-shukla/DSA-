class Solution {
public:
    int countOdd(vector<int>& nums, int k){
        if(k<0) return 0;
        int n = nums.size();
        int l=0, r=0;
        int oddCnt = 0;
        int cnt=0;

        while(r<n){
            if(nums[r]%2!=0) oddCnt++;
            while(oddCnt>k){
                if(nums[l]%2!=0) oddCnt--;
                l++;
            }
            cnt += r-l+1;
            r++;
        }

        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        return countOdd(nums,k) - countOdd(nums,k-1);
    }
};