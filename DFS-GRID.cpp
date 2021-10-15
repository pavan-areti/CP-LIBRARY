vec<vec<int>> vis(mxN);		
vec<vec<char>> g(mxN);

void dfs(int x, int y) {
    vis[x][y] = 1;
    rep(i, 0, 3) {
        if(!vis[x + dx[i]][y + dy[i]] and g[x + dx[i]][y + dy[i]] == '.') 
        dfs(x + dx[i], y + dy[i]);
    }
}
