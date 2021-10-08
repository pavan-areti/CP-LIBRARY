vec<int> kmp(string s) {
    int n = sz(s);
    vec<int> pi(n);
    rep(i, 1, n - 1) {
        int j = pi[i-1];
        while(j > 0 && s[i] != s[j])
            j = pi[j-1];
        if(s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
