class Solution {
public:
    int find(int x, vector<int> &par){
        if(par[x]==x){
            return x;
        }
        return par[x] = find(par[x],par);
    }

    vector<int> Union(int a, int b, vector<int> &par){

        int pa = find(a,par);
        int pb = find(b,par);

        if(pa!=pb){
            par[pa] = pb;
        }else{
            return {a,b};
        }
        return {};
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();

        vector<int> res;
        vector<int> par(n+1);

        for(int i=1; i<=n; i++){
            par[i]=i;
        }

        for(auto &e: edges){
            res = Union(e[0],e[1],par);

            if(!res.empty()){
                return res;
            }
        }

        return {};
    }
};