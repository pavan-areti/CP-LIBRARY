void dfs(int x, int y, vec<vec<bool>> &vis, vec<vec<char>> &g) {
    vis[x][y] = 1;
    rep(i, 0, 3) {
        if(!vis[x + dx[i]][y + dy[i]] and g[x + dx[i]][y + dy[i]] == '.') 
        dfs(x + dx[i], y + dy[i], vis, g);
    }
}
