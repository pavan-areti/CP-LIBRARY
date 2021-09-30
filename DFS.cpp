void dfs(int node, vec<bool> &vis, vec<vec<int>> &g) {
	vis[node] = 1;
	for(auto to : g[node]) {
		if(!vis[to]) dfs(to, vis, g);
	}
}
