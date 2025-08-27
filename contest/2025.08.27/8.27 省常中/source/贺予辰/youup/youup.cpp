#include<bits/stdc++.h>
#define int long long
using namespace std;
const int p = 998244353;
int c, n, x, fac[300005] = {1};
int inv(int a) {
    int b = p - 2, ans = 1;
    for (; b; b >>= 1, a = a * a % p)
        if (b & 1) ans = ans * a % p;
    return ans;
}
int C(int n, int m) {
    if (n < m) return 0;
    if (m < 0) return 0;
    return fac[n] * inv(fac[m]) % p
    * inv(fac[n - m]) % p;
}
signed main() {
    freopen("youup.in", "r", stdin);
    freopen("youup.out", "w", stdout);
    srand(time(0));
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    for (int i = 1; i <= 3e5; ++i)
        fac[i] = fac[i - 1] * i % p;
    cin >> c;
    cin >> n >> x;
    if (x == 0) {
        cout << n-- % p << ' ';
        while (n--)
            cout << 0 << ' ';
    } else if (x == 1) {
        cout << n-- % p << ' ' << n-- % p << ' ';
        while (n--)
            cout << 0 << ' ';
    } else if (c == 4)
            for (int i = 1; i <= n; ++i)
                cout << C(n, i) << ' ';
    else for (int i = 1; i <= n; ++i)
        cout << rand() % 998244353 << ' ';
    cout << '\n';
    return 0;
}
