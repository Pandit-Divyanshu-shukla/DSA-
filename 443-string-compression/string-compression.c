int compress(char* chars, int charsSize) {
    
    int st=0;
    int i=0;

    while(i<charsSize){
        int currCnt = 0;
        int lastChar = chars[i];
        while(i<charsSize && chars[i]==lastChar){
            currCnt++;
            i++;
        }

        chars[st++] = lastChar;

        if(currCnt>1){
            char buffer[10];
            int k=0;

            while(currCnt){
                buffer[k++] = (currCnt)%10 + '0';
                currCnt/=10;
            }

            // buffer[k] = '\0';

            while(k>0){
                k--;
                chars[st++] = buffer[k];
            }
        }
    }

    return st;
}