// used to multiply two long long

int mul(int a, int n) {
    int ret;
    if(n == 0)
       return 0;
    ret = mul(a, n/2);
    ret = (ret + ret) % mod;
    if(n % 2)
        ret = (ret + a) % mod;
    return ret;
}
