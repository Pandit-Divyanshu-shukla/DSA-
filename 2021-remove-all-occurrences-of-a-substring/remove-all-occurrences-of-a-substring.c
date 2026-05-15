char* removeOccurrences(char* s, char* part) {
    int n = strlen(s);
    int m = strlen(part);
    int currSize=0;

    

    char* ans = (char*) malloc(n+1*sizeof(char));

    for(int i=0; i<n; i++){
        ans[currSize++] = s[i];

        if(currSize>=m){
            bool isMatch = true;
            for(int i=0; i<m; i++){
                if(ans[currSize-m+i]!=part[i]){
                    isMatch = false;
                    break;
                }
            }

            if(isMatch){
                currSize-=m;
            }
        }

        
    }

    ans[currSize] = '\0';

    return ans;
}