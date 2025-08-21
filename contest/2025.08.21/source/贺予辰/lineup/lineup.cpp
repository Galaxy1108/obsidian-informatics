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
    if (n < 0) n = -n, putchar('-');
    if (n > 9) write(n / 10);
    putchar(n % 10 + '0');
}
using namespace std;
int n, h[51], ans = 0, t[51], c[205];
IL int fnd(int v, int cnt) {
    for (int i = 1; i <= n; ++i)
        if (t[i] == v)
            if ((--cnt) == 0)
                return i;
    return -1;
}
signed main() {
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);
    memset(c, 0, sizeof(c));
    n = read();
    for (RG int i = 1; i <= n; ++i)
        h[i] = read(), t[i] = h[i];
    sort(t + 1, t + 1 + n);
    for (RG int i = 1; i <= n; ++i)
        ans += abs(i - fnd(h[i], ++c[h[i]]));
    write(ans), putchar('\n');
    return 0;
}