class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st;
        unordered_set<int> ansst;
        vector<int> ans;
        for(int n: nums1)
            st.insert(n);
        
        for(int n:nums2){
            if(st.find(n)!=st.end()){
                ansst.insert(n);
            }
        }
        for(int x: ansst){
            ans.push_back(x);
        }
        return ans;
    }
};