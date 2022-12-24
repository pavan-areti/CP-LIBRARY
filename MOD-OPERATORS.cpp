inline lli add(lli a, lli b) {return (a + b >= mod ? a + b - mod : a + b);}

inline lli mul(lli a, lli b) {return (a * b) % mod;}

lli binpow(lli a, lli b) {
    lli res = 1;
    a %= mod;
    while(b) {
        if(b & 1) res = mul(res,a);
        a = mul(a,a);
        b >>= 1;
    }
    return res;
}

lli inv(lli x) {return binpow(x, mod - 2);}

lli modFact(lli n)
{
    lli ans = 1;
    for(int i=1;i<=n;i++){
        ans = mul(ans,i);
    }
    return ans%mod;
}
    
inline lli divide(lii x, lli y) {return mul(x, inv(y));}
