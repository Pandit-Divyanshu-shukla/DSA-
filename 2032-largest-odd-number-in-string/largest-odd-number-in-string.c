char* largestOddNumber(char* num) {

    int idx = strlen(num)-1;

    while(idx>=0){
        if((num[idx]-'0')%2==0){
            num[idx--] = '\0';
        }else{
            break;
        }
    }

    return num;
    
}