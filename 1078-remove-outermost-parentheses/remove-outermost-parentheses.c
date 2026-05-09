char* removeOuterParentheses(char* s) {
    int size = strlen(s);
    char* ans = (char*) malloc((size+1)*sizeof(char));

    int depth=0;
    int idx=0;

    for(int i=0; i<size; i++){
        if(s[i]=='('){
            if(depth>0){
                ans[idx++] = s[i];
            }
            depth++;
        }else{
            depth--;
            if(depth>0){
                ans[idx++] = s[i];
            }
        }
    }

    ans[idx]='\0';
    return ans;
}