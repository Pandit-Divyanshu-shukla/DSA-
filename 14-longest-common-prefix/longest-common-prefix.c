char* longestCommonPrefix(char** strs, int strsSize) {
    char *ans = (char*) malloc(201*sizeof(char));

    bool isPrsnt = true;
    int idx = 0;

    int n = strlen(strs[0]);
    for(int i=0; i<n; i++){
        char curr = strs[0][i];
        isPrsnt = true;
        for(int j=1; j<strsSize; j++){
            if(curr!=strs[j][i]){
                isPrsnt = false;
            }
        }

        if(isPrsnt) ans[idx++]=curr;
        else break;
    }

    ans[idx] = '\0';

    return ans;
}