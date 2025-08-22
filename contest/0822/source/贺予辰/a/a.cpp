#include<bits/stdc++.h>
#define int long long
#define IL inline
#define RG register
IL int read() {
    RG int ans = 0, fl = 1;
    RG char c = getchar();
    while (!isdigit(c)) {
        if (c == '-') fl = -1;
        c = getchar();
    }
    while (isdigit(c))
        ans = ans * 10 + c - '0',
        c = getchar();
    return ans * fl;
}
IL void write(RG int n) {
    if (n < 0) putchar('-'), n = -n;
    if (n > 9) write(n / 10);
    putchar(n % 10 + '0');
}
int n, m, p;
int f[4003][4003], g[4003][4003];
void buildg() {
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= m; ++j)
            g[i][j] = (g[i - 1][j] + g[i][j - 1]
            - g[i - 1][j - 1] + p + f[i][j]) % p;
}
int sumg(int l0, int r0, int l1, int r1) {
    --l0, --l1;
    return (g[r0][r1] -
    g[l0][r1] + p - g[r0][l1] + p
    + g[l0][l1]) % p;
}
signed main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    memset(f, 0, sizeof(f));
    memset(g, 0, sizeof(g));
    n = read(), m = read(), p = read();
    for (int i = 1; i <= m; ++i)
        for (int j = i; j <= m; ++j)
            f[i][j] = 1;
    buildg();
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= m; ++j)
            for (int k = j; k <= m; ++k){
                f[j][k] = (sumg(j + 1, k, k + 1, m)
                + sumg(1, j - 1, j, k - 1) +
                sumg(1, j, k, m) + sumg(j, k, j, k)
                - sumg(j, j, k, k) + p) % p;
            }
        buildg();
    }
    write(g[m][m]), putchar('\n');
    return 0;
}