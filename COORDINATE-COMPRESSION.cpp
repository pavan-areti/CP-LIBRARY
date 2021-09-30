vec<int> a(n);
vec<int> b = a;
sort(all(b));
map<int, int> m;

// 1 - based
rep(i, 1, n) {
    m[b[i]] = i;
}
rep(i, 0, n - 1) {
    a[i] = m[a[i]];
}
