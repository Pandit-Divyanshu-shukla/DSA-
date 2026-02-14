class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans;

        for(int i: nums){
            if(!mp.count(i)){
                mp[i] = 1;
            }else{
                mp[i] = mp[i]+1;
            }
        }

        for(pair<int,int> p: mp){
            if(p.second>=ceil(nums.size()/2.0)){
                ans = p.first;
                break;
            }
        }
        return ans;
    }
};