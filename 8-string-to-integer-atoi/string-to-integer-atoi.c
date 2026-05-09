int myAtoi(char* s) {
    bool neg=false;
    long ans=0;

        while(*s==' '){
            s++;
        }
        if(*s=='-'){
            neg=true;
            s++;
        }else if(*s=='+'){
            s++;
        }
        
        while(*s>='0' && *s <='9'){

            int digit = *s-'0';

            if(ans>INT_MAX/10){
                return neg? INT_MIN : INT_MAX;
            } 

            if(ans==INT_MAX/10){
                if((!neg && digit>7) || (neg && digit>8)){
                    return neg? INT_MIN : INT_MAX;
                }
            } 

            ans = ans*10 + digit;
            s++;
        }
        
    

    return neg? -1*ans : ans;
}