#include <unordered_map>
class Solution {
public:
    int t[301];
    bool solve(string& s, int idx, unordered_map<string,bool> &mp){

        if(idx == s.size() || mp.count(s.substr(idx))) return true;

        if(t[idx]!=-1) return t[idx];

        for(int len=1; idx+len<=s.size(); len++){
            string left = s.substr(idx,len);

            if(mp.count(left) && solve(s,idx+len,mp)){
                return t[idx] = true;
            }
        }
        return t[idx] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(t,-1,sizeof(t));
        unordered_map<string,bool> mp;
        for(string word : wordDict){
            mp[word] = 1; 
        }
        return solve(s,0,mp);
    }
};