class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cand1 = -78;
        int cand2 = -89;

        int cnt1 = 0;
        int cnt2 = 0;
        
        vector<int> ans;

        for(int x: nums){
            if(cand1==x){
                cnt1++;
            }
            else if(cand2==x){
                cnt2++;
            }
            else if(cnt1==0){
                cand1 = x;
                cnt1 = 1;
            }
            else if(cnt2==0){
                cand2 = x;
                cnt2 = 1;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0;
        cnt2 = 0;
        for(int i=0; i<nums.size(); i++){
            if(cand1==nums[i])cnt1++;
            else if(cand2==nums[i])cnt2++;
        }

        if(cnt1>nums.size()/3){
            ans.push_back(cand1);
        }
        if(cnt2>nums.size()/3){
            ans.push_back(cand2);
        }

        return ans;
    }
};