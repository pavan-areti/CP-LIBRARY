vec<int> vis(mxN);
vec<vec<int>> g(mxN);

void dfs(int node) {
	vis[node] = 1;
	for(auto to : g[node]) {
		if(!vis[to]) dfs(to);
	}
}
