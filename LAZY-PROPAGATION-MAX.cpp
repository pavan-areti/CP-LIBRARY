vec<int> a(mxN), tree_max(4 * mxN), lazy_max(4 * mxN);
void build_max(int node, int start, int end) {
    if(start == end) {
        tree_max[node] = a[start];
    }
    else {
        int mid = (start + end) / 2;
        build_max(2 * node, start, mid);
        build_max(2 * node + 1, mid + 1, end);
        tree_max[node] = max(tree_max[2 * node], tree_max[2 * node + 1]);
    }
}

void update_max(int node, int start, int end, int l, int r, int val) {
    if(lazy_max[node] != 0) { 
        tree_max[node] += lazy_max[node];
        if(start != end) {
            lazy_max[node * 2] += lazy_max[node];
            lazy_max[node * 2 + 1] += lazy_max[node];
        }
        lazy_max[node] = 0;
    }
    if(start > end or start > r or end < l) return;
    if(start >= l and end <= r) {
        tree_max[node] += val;
        if(start != end) {
            lazy_max[node * 2] += val;
            lazy_max[node * 2 + 1] += val;
        }
        return;
    }
    int mid = (start + end) / 2;
    update_max(node * 2, start, mid, l, r, val);
    update_max(node * 2 + 1, mid + 1, end, l, r, val);
    tree_max[node] = max(tree_max[node * 2], tree_max[node * 2 + 1]); 
}

int query_max(int node, int start, int end, int l, int r) {
    if(start > end or start > r or end < l)
        return LONG_MIN;         
    if(lazy_max[node] != 0) {
        tree_max[node] += lazy_max[node];            
        if(start != end) {
            lazy_max[node * 2] += lazy_max[node];
            lazy_max[node * 2 + 1] += lazy_max[node];
        }
        lazy_max[node] = 0;
    }
    if(start >= l and end <= r)
        return tree_max[node];
    int mid = (start + end) / 2;
    int p1 = query_max(node * 2, start, mid, l, r);
    int p2 = query_max(node * 2 + 1, mid + 1, end, l, r);
    return max(p1, p2);
}
