#include<bits/stdc++.h>
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
int g[2003][2003], n;
int min(int a, int b) {
    return a < b ? a : b;
}
signed main() {
    freopen("d.in", "r", stdin);
    freopen("d.out", "w", stdout);
    memset(g, 0, sizeof(g));
    n = read();
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            g[i][j] = g[j][i] = read();
    for (int i = 1; i <= n; ++i) {
        int ans = INT_MAX;
        for (int j = 1; j <= n; ++j)
            if (j != i) ans = min(ans, g[i][j]);
        write(ans * (n - 1));
        putchar('\n');
    }
    return 0;
}