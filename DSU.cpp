vec<int> par(mxN), rk(mxN);

void make(int v) {
    par[v] = v;
    rk[v] = 1;
}

int find(int v) {
    if (v == par[v])
        return v;
    return par[v] = find(par[v]);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (rk[a] < rk[b])
            swap(a, b);
        par[b] = a;
        rk[a] += rk[b];
    }
}
// TODO : rep(i, 1, n) make(i);
