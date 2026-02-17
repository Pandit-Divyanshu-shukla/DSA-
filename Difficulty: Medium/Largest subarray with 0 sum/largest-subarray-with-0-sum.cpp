#include <map>
class Solution {
  public:
    int maxLength(vector<int>& arr) {
        // code here
        map<int,int> mp;
        unordered_map<int,int> mm;
        int ans=0;
        mm[0]=-1;
        
        int sum = 0;
        for(int i=0; i<arr.size(); i++){
            sum+=arr[i];
            if(mm.count(sum)){
                ans = max(ans,i - mm[sum]);
                // cout<<ans<<endl;
                continue;
            }
            mm[sum]=i;
            // cout<<i<<" "<<sum<<endl;
        }
        
        
        
        
        
        // cout<<min<<" "<<max<<endl;
        
        
        
        return ans;
    }
};