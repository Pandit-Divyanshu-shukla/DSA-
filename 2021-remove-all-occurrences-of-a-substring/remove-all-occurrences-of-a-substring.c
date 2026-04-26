char* removeOccurrences(char* s, char* part) {

    int pLen = strlen(part);
    int sLen = strlen(s);

    char *res = (char*) malloc((sLen+1)*sizeof(char));

    int size=0;

    for(int i=0; i<sLen; i++){
        res[size++] = s[i];

        if(size>=pLen){
            int match = 1;

            for(int j=0; j<pLen; j++){
                if(res[size-pLen+j] != part[j]){
                    match = 0;
                    break;
                }
            }

            if(match){
                size -= pLen;
            }
        }
    }

    res[size] = '\0';

    return res;
}