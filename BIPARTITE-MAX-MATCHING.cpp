/**
 * Description: Simple bipartite matching algorithm. Graph $g$ should be a list
 * of neighbors of the left partition, and $btoa$ should be a vector full of
 * -1's of the same size as the right partition. Returns the size of
 * the matching. $btoa[i]$ will be the match for vertex $i$ on the right side,
 * or $-1$ if it's not matched.
 * Time: O(VE)
 * Usage: vi btoa(m, -1); dfsMatching(g, btoa); 
**/

bool find(int j, vec<vec<int>>& g, vec<int>& btoa, vec<int>& vis) {
    if(btoa[j] == -1) return 1;
    vis[j] = 1; int di = btoa[j];
    for(int e : g[di])
        if (!vis[e] && find(e, g, btoa, vis)) {
            btoa[e] = di;
            return 1;
        }
    return 0;
}

int max_bipartite_matching(vector<vec<int>>& g, vec<int>& btoa) {
    vec<int> vis;
    rep(i, 0, sz(g) - 1) {
        vis.assign(sz(btoa), 0);
        for (int j : g[i])
            if (find(j, g, btoa, vis)) {
                btoa[j] = i;
                break;
            }
    }
    return sz(btoa) - (int)count(all(btoa), -1);
}
