void floyd_warshall(int n, vector<vector<int>> &d) {
    const int INF = 2e9;
    for(int k = 1; k <= n; k ++)
        for(int i = 1; i <= n; i ++) 
            for(int j = 1; j <= n; j ++) {
                if(d[i][k] < INF && d[k][j] < INF)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);                 
            }
}
