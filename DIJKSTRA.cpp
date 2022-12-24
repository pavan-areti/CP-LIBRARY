void dijkstra(int s, vector<vector<pair<int, int>>> &g, vector<int> &d, vector<int> &p) {
    int n = (int)g.size() - 1;
    const int INF = 2e9;
    d.assign(n + 1, INF);
    p.assign(n + 1, -1);

    d[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, s});
    while(q.size()) {
        int v = q.top().second;
        int d_v = q.top().first;
        q.pop();
        if(d_v != d[v])
            continue;

        for(auto e : g[v]) {
            int to = e.first;
            int len = e.second;

            if(d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
}
