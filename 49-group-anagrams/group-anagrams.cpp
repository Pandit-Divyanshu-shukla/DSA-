class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> oldStrs = strs;
        vector<vector<string>> ans;

        unordered_map<string,vector<string>> mp;
        for(int i=0; i<strs.size(); i++){
            sort(strs[i].begin(),strs[i].end());
            mp[strs[i]].push_back(oldStrs[i]);
        }

        for(auto &p: mp){
            ans.push_back(p.second);
        }

        return ans;
    }
};