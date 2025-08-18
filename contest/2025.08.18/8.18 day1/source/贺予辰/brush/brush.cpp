#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[10004], f[10004][102];
int min(int a, int b) {
    return a < b ? a : b;
}
int max(int a, int b) {
    return a > b ? a : b;
}
signed main() {
    freopen("brush.in", "r", stdin);
    freopen("brush.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    int ans = 1e18;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= m; ++j)
            f[i][j] = 1e18;
    for (int i = 1; i <= min(n, m - 1); ++i) {
        f[i][0] = a[i];
        for (int j = i - 1; j >= max(1, i - m + 1);
        --j)
            for (int k = 0;
            k <= min(m - 1, m - i + j); ++k)
                f[i][i - j] =
                min(f[i][i - j], f[j][k] + a[i]);
    }
    for (int i = m; i <= n; ++i)
        for (int j = i - 1; j >= max(1, i - m + 1);
        --j)
            for (int k = 0;
            k <= min(m - 1, m - i + j); ++k)
                if (k == 0) {if (i <= m)
                f[i][i - j] =
                min(f[i][i - j], f[j][k] + a[i]);}
                else
                f[i][i - j] =
                min(f[i][i - j], f[j][k] + a[i]);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (i - j + m - 1 >= n)
            ans = min(ans, f[i][j]);
    cout << ans << '\n';
    return 0;
}