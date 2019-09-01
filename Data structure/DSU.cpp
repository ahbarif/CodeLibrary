struct UnionFind {
 
    int par[2 * N];
 
    int find_par(int n) {
        if (par[n]==n) return n;
        par[n]=find_par(par[n]);
        return par[n];
    }
 
    void union_(int x, int y) {
        int u = find_par(x);
        int v = find_par(y);
        if(u==v)    return;
        par[u] = v;
    }
 
    void init() {
        for(int i = 0; i<2*N; i++) par[i] = i;
    }
 
    bool is_Same(int u, int v) {
        if(find_par(u) == find_par(v)) return true;
        return false;
    }
 
} dsu;
