struct SegTree {
    int N;
    vector<int> a, tree;

    SegTree(int n) {
        N = n;
        a.resize(n + 1);
        tree.resize(4 * n + 1);  
    }

    int combine(int a, int b) {
        // return a + b;
    }

    void build(int node, int start, int end) {
        if(start == end) {
            tree[node] = a[start];
        }
        else {
            int mid = (start + end) / 2;
            build(2 * node, start, mid);
            build(2 * node + 1, mid + 1, end);
            tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
        }
    }
    void build() {build(1, 1, N);}

    void update(int idx, int val, int node, int start, int end) {
        if(start == end) {
            a[idx] = val;
            tree[node] = val;
            return;
        }
        int mid = start + (end - start)/2;
        if(start <= idx and idx <= mid) {
            update(idx, val, 2 * node, start, mid);
        }
        else {
            update(idx, val, 2 * node + 1, mid + 1, end);
        }
        tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
    }
    void update(int idx, int val) {update(idx, val, 1, 1, N);}

    int query(int l, int r, int node, int start, int end) {
        if(r < start or end < l) {
            return 0;
        }
        if(l <= start and end <= r) {
            return tree[node];
        }
        int mid = start + (end - start)/2; 
        return combine(query(l, r, 2 * node, start, mid), query(l, r, 2 * node + 1, mid + 1, end));
    }
    int query(int l, int r) {return query(l, r, 1, 1, N);}
};
