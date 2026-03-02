class Solution {
  public:
    string longestWord(vector<string> &words) {
        unordered_set<string> present;
        sort(words.begin(),words.end());
        string ans = "";
        for(string &st: words){
            if(st.size()==1 || present.count(st.substr(0,st.size()-1))){
                present.insert(st);
                if(st.size()>ans.size()){
                    ans = st;
                }
            }
        }
        
        return ans;
        
    }
};