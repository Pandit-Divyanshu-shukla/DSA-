class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int maxLen = INT_MIN;

        int maxFreq=0;

        int l=0, r=0;
        vector<int> freq(26,0);

        while(r<n){

            freq[s[r]-'A']++;
            maxFreq = max(maxFreq,freq[s[r]-'A']);
            // int changes = r-l+1 - maxFreq;

            while((r-l+1 - maxFreq)>k){
                freq[s[l]-'A']--;
                l++;
            }
            maxLen = max(maxLen,r-l+1);
            r++;
        }

        // for(int i=0; i<n; i++){
            

        //     vector<int> freq(26,0);
        //     for(int j=i; j<n; j++){
        //         freq[s[j]-'A']++;
        //         maxFreq = max(maxFreq,freq[s[j]-'A']);

        //         int changes = (j-i+1 - maxFreq);
        //         if(changes<=k){
        //             maxLen = max(maxLen,j-i+1);
        //         }
                
        //     }
        // }

        return maxLen;
    }
};