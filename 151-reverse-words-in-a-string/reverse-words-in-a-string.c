void reverse(char *s, int l, int r){
    while(l<r){
        int temp = s[l];
        s[l++] = s[r];
        s[r--] = temp;
    }
}

void removeSpaces(char*s, char *rev){
    int i =0;
    int idx=0;
    int n = strlen(s);
    while(i<strlen(s)){
        while(i<n && s[i]==' ') i++;
        while(i<n && s[i]!=' ') rev[idx++] = s[i++];
        while(i<n && s[i]==' ') i++;
        if(i<strlen(s)) rev[idx++] = ' ';
    }
    rev[idx]='\0';
}

char* reverseWords(char* s) {
    int n = strlen(s);
    int st=0;

    char* rev = (char*) malloc((n+1));
    int idx = 0;

    reverse(s,0,n-1);

    for(int i=0; i<=n; i++){
        if(s[i]==' ' || s[i]=='\0'){
           reverse(s,st,i-1);
           st = i+1;
        }
    }

    removeSpaces(s,rev);

    return rev;
}