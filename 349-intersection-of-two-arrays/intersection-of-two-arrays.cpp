class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st;

        vector<int> ans;
        for(int n: nums1)
            st.insert(n);
        
        for(int n:nums2){
            if(st.find(n)!=st.end()){
                ans.push_back(n);
                st.erase(n);
            }
        }
        return ans;
    }
};