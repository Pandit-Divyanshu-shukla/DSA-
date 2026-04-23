// User function template for C++
class Solution {
  public:
    bool chkZeros(unordered_map<char,int> &mp){
        
        for(auto &p: mp){
            if(p.second!=0){
                return false;
            }
        }
        return true;
        
    }
    int search(string &pat, string &txt) {
        int l=0, r=0;
        unordered_map<char,int> mp;
        
        int count=0;
        
        for(char ch: pat){mp[ch]++;}
        
        while(r<txt.length()){
            mp[txt[r]]--;
            if(r-l+1==pat.length()){
                if(chkZeros(mp)){
                    count++;
                }
                mp[txt[l]]++;
                l++;
            }
            r++;
        }
        return count;
    }
};