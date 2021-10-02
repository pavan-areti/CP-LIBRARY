vec<int> topo_sort(const vec<vec<int>> &g) {
    vec<int> indeg(sz(g)), ret;
    rep(i, 1, sz(g) - 1) for(int x : g[i]) indeg[x]++;
    queue<int> q; // use priority_queue for lexic. largest ans.
    rep(i, 1, sz(g) - 1) if(indeg[i] == 0) q.push(i);
    while(!q.empty()) {
        int i = q.front(); // top() for priority queue
        ret.push_back(i);
        q.pop();
        for(int x : g[i])
            if (--indeg[x] == 0) q.push(x);
    }
    return ret;
}
