#include<bits/stdc++.h>
using namespace std;
int n, a[55][55], m, ans = 0;
signed main() {
    freopen("brike.in", "r", stdin);
    freopen("brike.out", "w", stdout);
    cin >> n >> m;
    if (m == 0) {
        cout << 0 << '\n';
        return 0;
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n - i + 1; ++j)
            cin >> a[i][j], ans += a[i][j];
    cout << ans << '\n';
    return 0;
}