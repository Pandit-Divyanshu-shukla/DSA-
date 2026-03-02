class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map <string,vector<string>> mp;
        for(auto &st: strs){
            string ori = st;
            sort(st.begin(),st.end());
            mp[st].push_back(ori);
        }

        for(auto &m: mp){
            ans.push_back(m.second);
        }

        return ans;
    }
};