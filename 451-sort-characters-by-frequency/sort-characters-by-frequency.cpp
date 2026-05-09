#define pic pair<int,char>
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;

        string ans = "";

        for(char ch: s){
            mp[ch]++;
        }

        vector<pic> vec;
        for(auto &p: mp){
            vec.push_back({p.second,p.first});
        }

        sort(vec.begin(), vec.end(), greater<pic>());

        for(auto &it: vec){
            while(it.first){
                ans+=it.second;
                it.first--;
            }
        }

        return ans;
    }
};