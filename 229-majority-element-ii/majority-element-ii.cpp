class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map <int,int> mp;
        int limit = nums.size() / 3;
        cout<<limit<<endl;
        vector<int> ans;
        for(int i: nums){
            if(!mp.count(i)){
                mp[i] = 1;
            }else{
                mp[i]++;
            }
            
        }

        for(pair<int,int>p: mp){
            if(p.second>limit){
                ans.push_back(p.first);
            }
        }
        return ans;
    }
};