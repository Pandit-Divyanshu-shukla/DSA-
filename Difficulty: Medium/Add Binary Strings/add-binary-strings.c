// User function Template for C

char* trimZeros(char *st, int n){
    int i=0;
    
    while(i<n-1 && st[i]=='0'){
        i++;
    }
    
    return st+i;
}

char* addBinary(char s1[], char s2[]) {
    
    // code here
    char *st1 = trimZeros(s1, strlen(s1));
    char *st2 = trimZeros(s2, strlen(s2));
    
    int n1 = strlen(st1);
    int n2 = strlen(st2);
    
    int carry=0;
    
    int maxLen = (n1>n2) ? n1+2 : n2+2;
    
    char *ans = (char*)calloc(maxLen,sizeof(char));
    // ans[maxLen-1] = '\0';
    
    int i = n1-1;
    int j = n2-1;
    int k = maxLen-2;
    
    while(i>=0 || j>=0 || carry){
        int sum = carry;
        
        if(i>=0){
            sum+=st1[i--] - '0';
        }
        
        if(j>=0){
            sum+=st2[j--] - '0';
        }
        
        carry = sum/2;
        
        ans[k--] = (sum%2) + '0';
        
        
    }
    
    int start = k + 1;
    int idx = 0;
    
    while(ans[start]){
        ans[idx++] = ans[start++];
    }

    ans[idx] = '\0';
    
    // ans[maxLen] = '\0';
    
    return ans;
    
}