vec<int> a(mxN), tree_min(4 * mxN), lazy_min(4 * mxN);
void build_min(int node, int start, int end) {
    if(start == end) {
        tree_min[node] = a[start];
    }
    else {
        int mid = (start + end) / 2;
        build_min(2 * node, start, mid);
        build_min(2 * node + 1, mid + 1, end);
        tree_min[node] = min(tree_min[2 * node], tree_min[2 * node + 1]);
    }
}

void update_min(int node, int start, int end, int l, int r, int val) {
    if(lazy_min[node] != 0) { 
        tree_min[node] += lazy_min[node];
        if(start != end) {
            lazy_min[node * 2] += lazy_min[node];
            lazy_min[node * 2 + 1] += lazy_min[node];
        }
        lazy_min[node] = 0;
    }
    if(start > end or start > r or end < l) return;
    if(start >= l and end <= r) {
        tree_min[node] += val;
        if(start != end) {
            lazy_min[node * 2] += val;
            lazy_min[node * 2 + 1] += val;
        }
        return;
    }
    int mid = (start + end) / 2;
    update_min(node * 2, start, mid, l, r, val);
    update_min(node * 2 + 1, mid + 1, end, l, r, val);
    tree_min[node] = min(tree_min[node * 2], tree_min[node * 2 + 1]); 
}

int query_min(int node, int start, int end, int l, int r) {
    if(start > end or start > r or end < l)
        return LONG_MIN;         
    if(lazy_min[node] != 0) {
        tree_min[node] += lazy_min[node];            
        if(start != end) {
            lazy_min[node * 2] += lazy_min[node];
            lazy_min[node * 2 + 1] += lazy_min[node];
        }
        lazy_min[node] = 0;
    }
    if(start >= l and end <= r)
        return tree_min[node];
    int mid = (start + end) / 2;
    int p1 = query_min(node * 2, start, mid, l, r);
    int p2 = query_min(node * 2 + 1, mid + 1, end, l, r);
    return min(p1, p2);
}
