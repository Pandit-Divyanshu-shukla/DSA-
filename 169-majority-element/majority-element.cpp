class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i: nums){
            if(!mp.count(i)){
                mp[i] = 1;
            }else{
                mp[i] = mp[i]+1;
            }
            
        }

        int ans;
        for(pair<int,int> p: mp){
            cout<<p.first<<" "<<p.second<<endl;
        }
        for(pair<int,int> p: mp){
            if(p.second>=ceil(nums.size()/2.0)){
                cout<<ceil(nums.size()/2)<<endl;
                ans = p.first;
                break;
            }
        }
        return ans;
    }
};