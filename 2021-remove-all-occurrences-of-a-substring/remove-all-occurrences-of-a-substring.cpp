class Solution {
public:
    string removeOccurrences(string s, string part) {
        string res;
        
        for(char ch: s){
            res.push_back(ch);

            int subStrPos = res.size() - part.size();

            if(res.size()>=part.size() && res.substr(subStrPos)==part){
                res.erase(subStrPos,part.length());
            }
        }

        return res;
    }
};