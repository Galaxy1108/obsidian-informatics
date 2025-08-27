#include<bits/stdc++.h>
#define int long long
using namespace std;
int T;
int m, s, n, a[202];
bool f[2003][5003];
signed main() {
    freopen("give.in", "r", stdin);
    freopen("give.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--) {
        memset(f, 0, sizeof(f));
        cin >> m >> s >> n;
        for (int i = 1; i <= n; ++i)
            cin >> a[i], f[1][a[i]] = 1;
        if (m > 1e3 || s > 1e3) {
            cout << 0 << '\n';
            continue;
        }
        for (int i = 2; i <= m; ++i)
        for (int j = 1; j <= s; ++j)
        for (int k = 1; k <= n; ++k)
            if (j >= a[k])
                f[i][j] ^= f[i - 1][j - a[k]];
        cout << f[m][s] << '\n';
    }
    return 0;
}