vec<int> d(mxN), p(mxN), vis(mxN);

void bfs(int s, int n, vec<vec<int>> &g) {
    queue<int> q;
    rep(i, 1, n) {
        d[i] = p[i] = vis[i] = 0;
    }

    q.push(s);    
    vis[s] = 1;
    p[s] = -1;
    
    while(sz(q)) {
        int v = q.front();
        q.pop();
        for (int u : g[v]) {
            if (!vis[u]) {
                vis[u] = 1;
                q.push(u);
                d[u] = d[v] + 1;
                p[u] = v;
            }
        }
    }
}

vec<int> path_retrieve(int u) {
    if(!vis[u]) {
        return {};
    } 
    vector<int> path;
    for(int v = u; v != -1; v = p[v])
        path.pb(v);
    reverse(all(path));
    return path;
}
