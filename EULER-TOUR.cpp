vec<bool> vis(mxN);
vec<int> euler;

void dfs(int node, vec<vec<int>> &g) {
    vis[node] = true;
    euler.pb(node);
    for (auto to : g[node]) {
        if (!vis[to]) {
            dfs(to, g);
            euler.pb(node);
        }
    }
}
