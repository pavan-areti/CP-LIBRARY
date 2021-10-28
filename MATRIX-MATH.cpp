#define m 2
struct Matrix {
    // modify matrix size as per requirement
    int a[m][m] = {{0,0},{0,0}};
    Matrix operator *(const Matrix& other) {
        Matrix product;
        rep(i, 0, m - 1) rep(j, 0, m - 1) rep(k, 0, m - 1) {
            product.a[i][k] += a[i][j] * other.a[j][k];
        }
        return product;
    }
};

Matrix expo_power(Matrix a, int k) {
    Matrix product;
    rep(i, 0, m - 1) product.a[i][i] = 1;
    while(k > 0) {
        if(k % 2) {
            product = product * a;
        }
        a = a * a;
        k /= 2;
    }
    return product;
}
