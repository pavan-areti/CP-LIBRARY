void dijkstra(int s, vec<vec<pii>> &g, vec<int> &d, vec<int> &p) {
    int n = sz(g) - 1;
    d.assign(n + 1, INF);
    p.assign(n + 1, -1);

    d[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    while(sz(q)) {
        int v = q.top().ss;
        int d_v = q.top().ff;
        q.pop();
        if(d_v != d[v])
            continue;

        for(auto e : g[v]) {
            int to = e.ff;
            int len = e.ss;

            if(d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
}
