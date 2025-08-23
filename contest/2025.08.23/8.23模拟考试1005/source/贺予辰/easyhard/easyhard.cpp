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
    if (n < 0) n = -n, putchar('-');
    if (n > 9) write(n / 10);
    putchar(n % 10 + '0');
}
int n, m, p;
int qpow(int a, int b) {
    int ans = 1;
    for (; b; b >>= 1, a = a * a % p)
        if (b & 1) ans = ans * a % p;
    return ans;
}
signed main() {
    freopen("easyhard.in", "r", stdin);
    freopen("easyhard.out", "w", stdout);
    n = read(), m = read(), p = read();
    if (n <= m)
        write(qpow(2, n + m));
    else
        write(qpow(2, m << 1));
    putchar('\n');
    return 0;
}