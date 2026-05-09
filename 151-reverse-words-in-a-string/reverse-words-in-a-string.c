void reverse(char *s, int left, int right){    
    while(left<right){
        char temp = s[left];
        s[left++] = s[right];
        s[right--] = temp;
    }

}

void removeSpaces(char *s, char*rev){
    int n  =strlen(s);
    int i=0;
    int idx=0;

    while(i<n){
        while(i<n && s[i]==' ') i++;

        while(i<n && s[i]!=' '){
            rev[idx++] = s[i++];
        }

        while(i<n && s[i]==' '){
            i++;
        }

        if(i<n){
            rev[idx++] = ' ';
        }
    }

    rev[idx] = '\0';
}
char* reverseWords(char* s) {
    int n = strlen(s);
    char * rev= (char*) malloc((n+1)*sizeof(char));

    reverse(s,0,n-1);

    int st = 0;

    for(int i=0; i<=strlen(s); i++){
        if(s[i]==' ' || s[i]=='\0'){
            reverse(s,st,i-1);
            // s[i] = ' '; 
            st = i+1;
        }
    }

    removeSpaces(s,rev);

    return rev;
    
}