#define pii pair<int,int>
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        int ans=INT_MAX;

        for(int i=0; i<nums.size(); i++){
            mp[nums[i]].push_back(i);
        }

        for(auto &p: mp){
            auto &v = p.second;

            if(v.size()<3) continue;

            for(int i=0; i+2<v.size(); i++){
                int curr = 2*(v[i+2]-v[i]);
                ans = min(curr,ans);
            }
        }

        return ans==INT_MAX ? -1:ans;

        
        return ans;
    }
};