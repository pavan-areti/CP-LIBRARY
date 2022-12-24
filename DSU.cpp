struct DSU {
    int n;
    vector<int> par, rk;

    DSU(int n) {
        this->n = n;
        par.resize(n + 1);
        rk.resize(n + 1);        
        for(int i = 1; i <= n; i ++) {
            par[i] = i;
            rk[i] = 1;            
        }
    } 

    int find(int a) {
        if(a == par[a])
            return a;
        return par[a] = find(par[a]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if(a != b) {
            if (rk[a] < rk[b])
                swap(a, b);
            par[b] = a;
            rk[a] += rk[b];
        }
    }
};
