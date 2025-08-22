#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 10000010;

LL n, m, p, *f[2][N], g[N], *sum[2];

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    scanf("%lld%lld%lld", &n, &m, &p);
    for (int i = 0; i <= n; i++) {
        f[0][i] = new LL[m + 1]();
        f[1][i] = new LL[m + 1]();
    }
    sum[0] = new LL[m + 5]();
    sum[1] = new LL[m + 5]();
    // cout << "qwq" << endl;
    g[0] = 1;
    for (int i = 1; i <= n; i++) {
        // cout << "i = " << i << endl;
        for (int j = 1; j <= m; j++)
            sum[1][j] = sum[1][j - 1] + f[1][i - 1][j];
        for (int j = m; j >= 1; j--)
            sum[0][j] = sum[0][j + 1] + f[0][i - 1][j];
        LL res = 0;
        for (int j = 1; j <= m; j++) {
            f[0][i][j] = (f[0][i][j] - sum[1][j - 1] * (m - j + 1) % p + p) % p;
            f[0][i][j] = (f[0][i][j] + g[i - 1] * (m - j + 1)) % p;
        }
        for (int j = m; j >= 1; j--) {
            f[0][i][j] = (f[0][i][j] - res + p) % p;
            res = (res + sum[0][j]) % p;
        }
        // cout << "qwq" << endl;
        for (int j = m; j >= 1; j--) {
            f[1][i][j] = (f[1][i][j] - sum[0][j + 1] * j % p + p) % p;
            f[1][i][j] = (f[1][i][j] + g[i - 1] * j) % p;
        }
        res = 0;
        for (int j = 1; j <= m; j++) {
            f[1][i][j] = (f[1][i][j] - res + p) % p;
            res = (res + sum[1][j]) % p;
        }
        g[i] = (g[i] + g[i - 1] * (m + 1) * m / 2) % p;
        // cout << "i = " << i << " g = " << g[i] << endl;
        for (int j = 1; j <= m; j++) {
            g[i] = (g[i] - f[0][i - 1][j] * j * (j - 1) / 2 % p + p) % p;
            g[i] = (g[i] - f[1][i - 1][j] * (m - j + 1) * (m - j) / 2 % p + p) % p;
        }
        // for (int j = 1; j <= m; j++)
        //     printf("f[0][%d][%d] = %lld, f[1][%d][%d] = %lld\n", i, j, f[0][i][j], i, j, f[1][i][j]);
        // cout << "i = " << i << " g = " << g[i] << endl;
    }
    printf("%lld\n", g[n]);
    return 0;
}
/*
3 2 100000007
*/