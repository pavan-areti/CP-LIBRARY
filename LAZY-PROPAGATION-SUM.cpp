vec<int> a(mxN), tree_sum(4 * mxN), lazy_sum(4 * mxN);

void build_sum(int node, int start, int end) {
    if(start == end) {
        tree_sum[node] = a[start];
    }
    else {
        int mid = (start + end) / 2;
        build_sum(2 * node, start, mid);
        build_sum(2 * node + 1, mid + 1, end);
        tree_sum[node] = tree_sum[2 * node] + tree_sum[2 * node + 1];
    }
}

void update_sum(int node, int start, int end, int l, int r, int val) {
    if(lazy_sum[node] != 0) { 
        tree_sum[node] += (end - start + 1) * lazy_sum[node];
        if(start != end) {
            lazy_sum[node * 2] += lazy_sum[node];
            lazy_sum[node * 2 + 1] += lazy_sum[node];
        }
        lazy_sum[node] = 0;
    }
    if(start > end or start > r or end < l) return;
    if(start >= l and end <= r) {
        tree_sum[node] += (end - start + 1) * val;
        if(start != end) {
            lazy_sum[node * 2] += val;
            lazy_sum[node * 2 + 1] += val;
        }
        return;
    }
    int mid = (start + end) / 2;
    update_sum(node * 2, start, mid, l, r, val);
    update_sum(node * 2 + 1, mid + 1, end, l, r, val);
    tree_sum[node] = tree_sum[node * 2] + tree_sum[node * 2 + 1]; 
}

int query_sum(int node, int start, int end, int l, int r) {
    if(start > end or start > r or end < l)
        return 0;         
    if(lazy_sum[node] != 0) {
        tree_sum[node] += (end - start + 1) * lazy_sum[node];            
        if(start != end) {
            lazy_sum[node * 2] += lazy_sum[node];
            lazy_sum[node * 2 + 1] += lazy_sum[node];
        }
        lazy_sum[node] = 0;
    }
    if(start >= l and end <= r)
        return tree_sum[node];
    int mid = (start + end) / 2;
    int p1 = query_sum(node * 2, start, mid, l, r);
    int p2 = query_sum(node * 2 + 1, mid + 1, end, l, r);
    return (p1 + p2);
}
