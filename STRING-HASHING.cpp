struct Hasher {
    int n, p, mod;
    vec<int> fHash, rHash;
    vec<int> pk;
    Hasher(const string &s, int _p, int _mod) {
        mod = _mod, p = _p;
        n = sz(s);
        fHash.resize(n);
        rHash.resize(n);
        pk.resize(n);        

        pk[0] = 1;
        rep(i, 1, n - 1) pk[i] = (pk[i - 1] * p) % mod;
        
        fHash[0] = (s[0] - 'a' + 1);
        rep(i, 1, n - 1) {
            fHash[i] = (fHash[i - 1] * p + (s[i] - 'a' + 1)) % mod;
        }

        rHash[n - 1] = (s[n - 1] - 'a' + 1);
        repr(i, n - 2, 0) {
            rHash[i] = (rHash[i + 1] * p + (s[i] - 'a' + 1)) % mod;
        }
    }

    int get_fHash(int l, int r) {
        if(l == 0) return fHash[r];
        return (fHash[r] - (fHash[l - 1] * pk[r - l + 1]) % mod + mod) % mod;    
    }

    int get_rHash(int l, int r) {
        if(r == n - 1) return rHash[l];
        return (rHash[l] - (rHash[r + 1] * pk[r - l + 1]) % mod + mod) % mod;    
    }
};
