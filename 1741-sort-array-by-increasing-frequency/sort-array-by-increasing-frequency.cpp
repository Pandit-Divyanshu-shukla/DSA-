class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> freq;
        vector<int> ans;

        for(int i:nums) freq[i]++;
        vector<vector<int>> sorted(101);

        for(auto freq: freq){
            sorted[freq.second].push_back(freq.first);
        }

        for(int i=0; i<101; i++){
            if(!sorted[i].empty()){
                sort(sorted[i].begin(),sorted[i].end(),greater<int>());
            }
            for(int j=0; j<sorted[i].size(); j++){
                int cnt=i;
                while(cnt-->0){
                    ans.push_back(sorted[i][j]);
                }
            }
        }

        return ans;
    }
};