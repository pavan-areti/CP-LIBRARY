struct P {
    vec<int> d, p;
    vec<bool> vis;
};

P bfs(int s, int n, vec<vec<int>> &g) {
    queue<int> q;
    vec<int> d(n + 1, 0), p(n + 1, 0);
    vec<bool> vis(n + 1, 0);

    q.push(s);    
    vis[s] = true;
    p[s] = -1;
    
    while(sz(q)) {
        int v = q.front();
        q.pop();
        for (int u : g[v]) {
            if (!vis[u]) {
                vis[u] = true;
                q.push(u);
                d[u] = d[v] + 1;
                p[u] = v;
            }
        }
    }

    return {d, p, vis};
}

vec<int> path_retrieve(int u, vec<int> &p, vec<int> &vis) {
    if(!vis[u]) {
        return {};
    } 
    vector<int> path;
    for(int v = u; v != -1; v = p[v])
        path.pb(v);
    reverse(all(path));
    return path;
}
