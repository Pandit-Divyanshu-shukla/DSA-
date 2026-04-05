class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int p=1;
        int c0=0;
        vector<int> zeros;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0){
                c0++;
                continue;
            }
            p*=nums[i];
        }

        // cout<<p<<" "<<p0<<endl;

        vector<int> ans;

        for(int i: nums){
            if(i==0){
                if(c0-1==0){
                    ans.push_back(p);
                }else{
                    ans.push_back(0);
                }
            }else{
                if(c0!=0){
                    ans.push_back(0);
                }else{
                    ans.push_back((int)(p/i));
                }
            }
        }

        return ans;
    }
};