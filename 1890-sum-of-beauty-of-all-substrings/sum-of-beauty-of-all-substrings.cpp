class Solution {
public:
    
    int beauty(int freq[]){

        int minFreq = INT_MAX;
        int maxFreq = INT_MIN;

        for(int i=0; i<26; i++){
            if(freq[i]==0) continue;
            minFreq = min(minFreq,freq[i]);
            maxFreq = max(maxFreq,freq[i]);
        }

        if((maxFreq == INT_MIN) || (minFreq==INT_MAX)){
            return 0;
        }

        return maxFreq - minFreq;
    }
    int beautySum(string s) {
        int ans = 0;
        
        for(int i=0; i<s.length(); i++){
            string sub="";
            int freq[26] = {0};
            for(int j=i; j<s.length(); j++){
                freq[s[j]-'a']++;
                // sub+=s[j];
                ans+= beauty(freq);
            }
        }

        return ans;
    }
};