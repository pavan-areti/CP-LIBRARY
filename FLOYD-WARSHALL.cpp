void floyd_warshall(int n, vec<vec<int>> &d) {
    rep(k, 1, n) {
        rep(i, 1, n) {
            rep(j, 1, n) {
                if(d[i][k] < INF && d[k][j] < INF)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
            }
        }
    }    
}
