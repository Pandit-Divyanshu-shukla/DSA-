int numberOfSubstrings(char* s) {
    int freq[3] = {0};
    int l=0, r=0;
    int cnt=0;

    while(r<strlen(s)){
        freq[s[r]-'a']++;
        while(freq[0]>=1 && freq[1]>=1 && freq[2]>=1){
            cnt+=strlen(s)-r;
            freq[s[l]-'a']--;
            l++;
        }
        r++;
    }

    return cnt;
}