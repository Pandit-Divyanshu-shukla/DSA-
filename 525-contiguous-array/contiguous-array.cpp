#include <unordered_map>
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp;
        int sum=0;
        int ans=0;
        mp[0]=-1;
        for(int i=0; i<nums.size(); i++){
            if(!nums[i]){
                nums[i]=-1;
            }
        }
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            if(mp.count(sum)){
                ans = max(ans,i-mp[sum]);
            }else{
                mp[sum] = i;
            }
        }

        return sum==0 ? nums.size() : ans;
    }
};