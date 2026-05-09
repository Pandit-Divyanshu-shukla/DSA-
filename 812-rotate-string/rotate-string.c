bool rotateString(char* s, char* goal) {
    if(strlen(s)!=strlen(goal)) return false;
    char temp[205];

    strcpy(temp,s);
    strcat(temp,s);

    // To find substring
    return strstr(temp,goal);
}