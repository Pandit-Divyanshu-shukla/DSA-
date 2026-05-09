bool isAnagram(char* s, char* t) {
    int freqS[26];

    if(strlen(s)!=strlen(t)) return false;

    for(int i=0; i<26; i++){
        freqS[i]=0;
    }

    for(int i=0; i<strlen(s); i++){
        freqS[s[i]-'a']++;
    }

    for(int i=0; i<strlen(t); i++){
        freqS[t[i]-'a']--;
    }

    for(int i=0; i<26; i++){
        if(freqS[i])return false;
    }

    return true;
}