class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int currIdx = 0;
        bool isPrsnt = true;
        string ans="";
        for(int i=0; i<strs[0].size(); i++){
            char curr = strs[0][i];
            for(int j=1; j<strs.size(); j++){
                if(curr!=strs[j][i]){
                    isPrsnt = false;
                }
            }
            if(!isPrsnt) break;
            else ans+=curr;
        }

        return ans;
    }
};