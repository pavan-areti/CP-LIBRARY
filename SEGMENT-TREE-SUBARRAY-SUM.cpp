struct info {
    int sum, pref, suff, ans;
};

vec<int> a(mxN);
vec<info> tree(4 * mxN);

info combine(info l, info r) {
    info res;
    res.sum = l.sum + r.sum;
    res.pref = max(l.pref, l.sum + r.pref);
    res.suff = max(r.suff, r.sum + l.suff);
    res.ans = max(max(l.ans, r.ans), l.suff + r.pref);
    return res;
}

info make_info(int val) {
    info res;
    res.sum = val;
    res.pref = res.suff = res.ans = max(0ll, val);
    return res;
}

void build(int node, int start, int end) {
    if(start == end) {
        tree[node] = make_info(a[start]);
    }
    else {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
    }
}

void update(int node, int start, int end, int idx, int val) {
    if(start == end) {
        tree[node] = make_info(val);
    }
    else {
        int mid = (start + end) / 2;
        if(start <= idx and idx <= mid) {
            update(2 * node, start, mid, idx, val);
        }
        else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
    }
}

info query(int node, int start, int end, int l, int r) {
    if(r < start or end < l) {
        return make_info(0);
    }
    if(l <= start and end <= r) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    info p1 = query(2 * node, start, mid, l, r);
    info p2 = query(2 * node + 1, mid + 1, end, l, r);
    return combine(p1, p2);
}
