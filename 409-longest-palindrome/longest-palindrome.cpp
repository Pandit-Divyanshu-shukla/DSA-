class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;

        bool isOdd = false;
        int ans=0;

        for(char i: s){
            mp[i]++;
        }

        for(auto &p: mp){
            if(p.second%2!=0) isOdd = true;
            ans += (p.second/2)*2;
        }

        if(isOdd)return ans+1;
        else return ans;
    }
};