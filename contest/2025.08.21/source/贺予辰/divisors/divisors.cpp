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
int n;
int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a % b);
}
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}
signed main() {
    freopen("divisors.in", "r", stdin);
    freopen("divisors.out", "w", stdout);
    n = read();
    int ans = 1;
    for (int i = 1; i <= n; ++i)
        ans = lcm(ans, i);
    write(ans), putchar(' ');
    for (int i = 2; i <= n; ++i)
        write(i), putchar(' ');
    putchar('\n');
    for (int i = 2; i <= n; ++i)
        write(1), putchar(' '),
        write(i), putchar('\n');
    return 0;
}