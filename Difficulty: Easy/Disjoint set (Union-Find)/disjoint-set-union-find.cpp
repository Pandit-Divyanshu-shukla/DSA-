/*Complete the functions below*/
int find(int par[], int x) {
    // add code here
    if(par[x]==x){
        return x;
    }
    return par[x]=find(par,par[x]);
}

void unionSet(int par[], int x, int z) {
    // add code here.
    int parA = find(par,x);
    int parB = find(par,z);
    
    if(parA!=parB){
        par[parA] = parB;
    }
    
    // if(rank[parA]==rank[parB]){
    //     par[parA] = parB;
    //     rank[parA]++;
    // }
    // else if(rank[parA]>rank[parB]){
    //     par[parA] = parB;
    // }
    // else{
    //     par[parB] = parA;
    // }
}