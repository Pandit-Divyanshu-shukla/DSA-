int maxDepth(char* s) {
    int depth=0;
    int maxDepth=0;

    for(int i=0; i<strlen(s); i++){
        if(s[i]=='('){
            depth++;
            maxDepth = (maxDepth>depth) ? maxDepth:depth ;
        }else if(s[i]==')'){
            depth--;
        }
    }

    return maxDepth;
}