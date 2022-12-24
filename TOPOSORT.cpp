vector<int> topo_sort(const vector<vector<int>> &g) {
    vector<int> indeg(g.size()), ret;
    for(int i = 1; i < (int)g.size(); i ++)
        for(int v : g[i]) indeg[v] ++;

    queue<int> q; // use priority_queue for lexic. largest ans.

    for(int i = 1; i < (int)g.size(); i ++)
        if(indeg[i] == 0) q.push(i);

    while(!q.empty()) {
        int i = q.front(); // top() for priority queue
        ret.push_back(i);
        q.pop();
        for(int x : g[i])
            if(--indeg[x] == 0) q.push(x);
    }

    return ret;
}
