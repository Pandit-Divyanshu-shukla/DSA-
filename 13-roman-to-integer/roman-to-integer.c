int value(char ch){
    switch(ch){
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}
int romanToInt(char* s) {
    int ans=0;
    while(*s){
        if(*(s+1)!='\0' && value(*(s+1))>value(*(s))){
            ans-=value(*s);
        }else{
            ans+=value(*s);
        }
        s++;
    }

    return ans;
}