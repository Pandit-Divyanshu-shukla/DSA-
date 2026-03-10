// User function Template for C++
class Solution {
  public:
    int find(int x, vector<int> &par)
    {
        if (par[x] == x)
        {
            return x;
        }
        // Path Compression
        return par[x] = find(par[x],par);
    }

    void Union(int a, int b,vector<int> &par,vector<int> &rank)
    {
        int parA = find(a,par);
        int parB = find(b,par);

        if (rank[parA] == rank[parB])
        {
            // take parA
            par[parB] = parA;
            rank[parA]++;
        }
        else if (rank[parA] > rank[parB])
        {
            // take parA
            par[parB] = parA;
        }
        else
        {
            // take parB
            par[parA] = parB;
        }
    }

    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
        int cost = 0;
        auto myLambda = [](auto &a, auto &b)
        {
            return a[2] < b[2];
        };
        
        vector<int> rank(V,0);
        vector<int> par(V);
        
        for (int i = 0; i < V; i++)
        {
            par[i] = i;
        }
        
        sort(edges.begin(), edges.end(), myLambda);
        for (auto &e : edges)
        {
            int u = e[0];
            int v = e[1];
            int wt = e[2];

            int pu = find(u,par);
            int pv = find(v,par);

            if (pu != pv)
            {
                Union(pu, pv,par, rank);
                cost += wt;
            }
        }

        return cost;
    }
};