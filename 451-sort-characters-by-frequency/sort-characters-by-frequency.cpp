#define pic pair<int,char>
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        vector<pic> vec;
        for(char ch: s){
            mp[ch]++;
        }

        for(auto &p: mp){
            vec.push_back({p.second,p.first});
        }

        sort(vec.begin(),vec.end(),greater<pic>());

        string ans = "";
        for(auto &p : vec){
            while(p.first--){
                ans+=p.second;
            }
        }

        return ans;
    }
};