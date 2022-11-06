struct Edge {
    int U, V, Wt;
    bool operator<(Edge const& other) {
        return Wt < other.Wt;
    }
};

struct Kruskal {
    int N, Cost;
    vector<Edge> Edg;
    vector<Edge> Res;
    vector<int> Par, Rk;

    void Make(int U) {
        Par[U] = U;
        Rk[U] = 1;
    }

    int Find(int U) {
        if(U == Par[U])
            return U;
        return Par[U] = Find(Par[U]);
    }

    void Unite(int U, int V) {
        U = Find(U);
        V = Find(V);
        if(U != V) {
            if (Rk[U] < Rk[V])
                swap(U, V);
            Par[V] = U;
            Rk[U] += Rk[V];
        }
    }

    Kruskal(int n, int q, vector<Edge> edg) {
        int N = n;
        Edg = edg;
        Cost = 0;
        Par.resize(N + 1, 0);
        Rk.resize(N + 1, 0);
        for(int i = 1; i <= N; ++ i) Make(i);
    }

    void MST() {
        sort(Edg.begin(), Edg.end());
        for(Edge e : Edg) {
            if(Find(e.U) != Find(e.V)) {
                Cost += e.Wt;
                Res.push_back(e);
                Unite(e.U, e.V);
            }                
        }
    }
};
