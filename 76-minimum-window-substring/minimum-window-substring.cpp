class Solution {
public:
    string minWindow(string s, string t) {

        string ans = "";

        int n = s.length();
        
        int minLength = INT_MAX;
        int s_idx = 0;
        int cnt = 0;

        unordered_map<char,int> mp;
        for(char ch: t){
            mp[ch]++;
        }

        int l=0, r=0;



        while(r<n){
            if(mp[s[r]]>0) cnt++;
            mp[s[r]]--;

            if(cnt==t.length()){
                if(r-l+1<minLength){
                    minLength = r-l+1;
                    s_idx=l;
                }
            }

            while(cnt>=t.length()){
                mp[s[l]]++;
                if(mp[s[l]]>0){
                    if(r-l+1<minLength){
                        minLength = r-l+1;
                        s_idx=l;
                    }
                    cnt--;
                } 
                l++;
            }
            r++;
        }

        // for(int i=0; i<n; i++){
        //     cnt=0;
        //     unordered_map<char,int> freq;
        //     for(char ch: t){
        //         freq[ch]++;
        //     }
        //     for(int j=i; j<n; j++){
        //         if(freq[s[j]]>0){
        //             cnt++;
        //         }
        //         freq[s[j]]--;

        //         if(cnt==t.length()){
        //             if(j-i+1<minLength){
        //                 minLength = j-i+1;
        //                 s_idx = i;
        //             }
        //             break;
        //         }
        //     }
        // }

        return minLength == INT_MAX ? "" : s.substr(s_idx, minLength);
    }
};