class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> ans; //n

        unordered_map<string,vector<string>> mp; // n*k
        for(int i=0; i<strs.size(); i++){  //n
            string tmp = strs[i];
            sort(strs[i].begin(),strs[i].end());   //klogk
            mp[strs[i]].push_back(tmp);
        }

        for(auto &p: mp){
            ans.push_back(p.second);
        }

        return ans;
    }
};