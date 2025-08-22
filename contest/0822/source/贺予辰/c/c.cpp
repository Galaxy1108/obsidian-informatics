#include<bits/stdc++.h>
#define IL inline
#define RG register
const int MAXN = 5010;
int a[MAXN][MAXN], n, seed;
void gen(int n, int seed) {
    std::mt19937 rng(seed);
    for(int i = 1; i <= n; ++i)
        for(int j = 1;j <= n + 1; ++j)
            a[i][j] = j,
            std::swap
            (a[i][j], a[i][rng() % j + 1]);
}
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
signed main() {
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    n = read(), seed = read();
    if (seed) gen(n, seed);
    else
        for (RG int i = 1; i <= n; ++i)
            for (RG int j = 1; j <= n + 1; ++j)
                a[i][j] = read();
    for (int i = 1; i <= n; ++i) {
        int tmp = INT_MIN, ans = 0;
        for (int j = 1; j <= n + 1; ++j)
            if (a[i][j] > tmp)
                ans = j, tmp = a[i][j];
        write(ans), putchar(' ');
    }
    return 0;
}