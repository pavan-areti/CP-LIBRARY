inline int add(int a, int b) {return (a + b >= mod ? a + b - mod : a + b);}

inline int mul(int a, int b) {return a * b % mod;}

int binpow(int a, int b) {
    int res = 1;
    a %= mod;
    while(b) {
        if(b & 1) res = mul(res,a);
        a = mul(a,a);
        b >>= 1;
    }
    return res;
}

int inv(int x) {return binpow(x, mod - 2);}

inline int divide(int x, int y) {return mul(x, inv(y));}
