class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_set<int> st;
        unordered_set<int> ansst;
        for(int x: nums1){
            st.insert(x);
        }
        for(int y: nums2){
            if(st.find(y)!=st.end()){
                ansst.insert(y);
            }
        }

        for(int z: ansst){
            ans.push_back(z);
        }
        return ans;

    }
};