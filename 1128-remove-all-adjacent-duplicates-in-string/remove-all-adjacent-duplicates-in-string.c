char* removeDuplicates(char* s) {
    int n = strlen(s);
    char* ans = (char*) malloc(n+1*sizeof(char));

    int size = -1;
    char prev='a';

    // ans[size] = s[0];
    for(int i=0; i<n; i++){
        if(size>=0 && s[i]==ans[size]){
            size--;
        }else{
            size++;
            ans[size] = s[i];
        }       
    }

    ans[size+1] = '\0';

    return ans;
}