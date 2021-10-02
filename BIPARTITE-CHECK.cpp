bool binpartite_check(vec<vec<int>> &g) {
    int n = sz(g) - 1;
    vec<int> side(n + 1, -1);
    bool is_bipartite = true;
    queue<int> q;
    rep(st, 1, n) {
        if(side[st] == -1) {
            q.push(st);
            side[st] = 0;
            while(sz(q)) {
                int v = q.front();
                q.pop();
                for (int u : g[v]) {
                    if(side[u] == -1) {
                        side[u] = side[v] ^ 1;
                        q.push(u);
                    } else {
                        is_bipartite &= side[u] != side[v];
                    }
                }
            }
        }
    }

    return is_bipartite;
}
