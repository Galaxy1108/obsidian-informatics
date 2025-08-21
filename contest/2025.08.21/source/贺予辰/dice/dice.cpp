#include<bits/stdc++.h>
#define IL inline
#define RG register
#define int long long
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
const int p = 1e9 + 7;
int n, a[5003], cnt = 0, prd[5003], ans = 0;
IL int qpow(RG int a, RG int b) {
    RG int ans = 1;
    if (a == 1 || b == 0) return 1;
    if (a == 0) return 0;
    if (b < 0)
        a = qpow(a, p - 2), b = -b;
    for (; b; b >>= 1, a = a * a % p)
        if (b & 1) ans = ans * a % p;
    return ans;
}
IL int cal(int i) {
    int ans = 0;
    for (RG int t = a[i - 1]; t < a[i]; ++t)
        ans = (ans + qpow(t, n - i + 1)) % p;
    return ans * qpow(prd[i], p - 2) % p;
}
signed main() {
    freopen("dice.in", "r", stdin);
    freopen("dice.out", "w", stdout);
    n = read(), a[0] = 0;
    for (RG int i = 1; i <= n; ++i)
        a[i] = read();
    sort(a + 1, a + n + 1);
    prd[n + 1] = 1;
    for (RG int i = n; i; --i)
        prd[i] = prd[i + 1] * a[i] % p;
    for (int i = 1; i <= n; ++i)
        if (a[i] != a[i - 1])
            ans = (ans + (a[i] - a[i - 1] -
            cal(i) + p) % p) % p;
    write(ans), putchar('\n');
    return 0;
}
