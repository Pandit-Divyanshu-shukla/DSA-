class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        unordered_set <int> st;

        int longest=1;

        for(int i: nums){
            st.insert(i);
        }


        for(int i: st){
            int cnt=1;
            if(st.find(i-1)==st.end()){
                while(st.find(i+1)!=st.end()){
                    cnt++;
                    i++;
                }
                longest = max(longest,cnt);
            }
        }

        // sort(nums.begin(),nums.end());
        // int cnt=1;
        // int longest=1;
        // for(int i=1; i<nums.size(); i++){
        //     if(abs(nums[i]-nums[i-1])==1){
        //         cnt++;
        //     }
        //     else if(nums[i]==nums[i-1]){
        //         continue;
        //     }
        //     else{
        //         longest = max(longest,cnt);
        //         cnt=1;
        //     }
        // }
        return longest;
        
    }
};