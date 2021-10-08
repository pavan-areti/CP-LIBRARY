struct Hasher {
    int n, p, mod;
    vec<int> fHash;
    vec<int> pk;
    Hasher(string s, int _p, int _mod) {
        mod = _mod, p = _p;
        n = sz(s);
        fHash.resize(n);
        pk.resize(n);        
        fHash[0] = (s[0] - 'a' + 1);
        pk[0] = 1;
        rep(i, 1, n - 1) {
            fHash[i] = (fHash[i - 1] * p + (s[i] - 'a' + 1)) % mod;
            pk[i] = (pk[i - 1] * p) % mod;
        }
    }

    int get_hash(int l, int r) {
        if(l == 0) return fHash[r];
        return (fHash[r] - fHash[l - 1] * pk[r - l + 1] + mod) % mod;    
    }
};
