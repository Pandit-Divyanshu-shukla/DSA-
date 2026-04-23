class Solution {
public:
    bool chkZeros(unordered_map<char,int> &freq){
        for(auto &p: freq){
            if(p.second!=0){
                return false;
            }
        }

        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        vector<int> ans;

        int l=0, r=0;
        unordered_map<char,int> freq;

        for(char c: p) freq[c]++;

        while(r<n){
            freq[s[r]]--;
            if(r-l+1==p.length()){
                if(chkZeros(freq)){
                    ans.push_back(l);
                }
                freq[s[l]]++;
                l++;
            }
            r++;
        }

        return ans;
    }
};