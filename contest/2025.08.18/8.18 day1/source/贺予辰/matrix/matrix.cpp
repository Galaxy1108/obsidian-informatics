#include<bits/stdc++.h>
using namespace std;
int n, m, k;
int a[3][101], f[3][101][11], s[3][101];
int sum(int xa, int ya, int xb, int yb) {
    --xa, --ya;
    return s[xb][yb] - s[xb][ya] - s[yb][xa]
    + s[xa][ya];
}
int main() {
    freopen("matrix.in", "r", stdin);
    freopen("matrix.out", "w", stdout);
    memset(f, 0, sizeof(f));
    memset(s, 0, sizeof(s));
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    int ans = INT_MIN;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[j][i],
            s[j][i] = s[j - 1][i] + s[j][i - 1] -
            s[j - 1][i - 1] + a[j][i];
    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
        f[j][i][1] = INT_MIN;
        for (int y = 1; y <= i; ++y)
        for (int x = 1; x <= j; ++x)
            f[j][i][1] = max(f[j][i][1],
            sum(x, y, j, i));
    }
    for (int t = 2; t <= k; ++t)
        for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            f[j][i][t] = INT_MIN;
            for (int y = 1; y < i; ++y)
            for (int x = 1; x < j; ++x) {
                for (int yy = y + 1; yy <= i; ++yy)
                for (int xx = 1; xx <= j; ++xx)
                    f[j][i][t] = max(f[j][i][t],
                    f[x][y][t - 1] +
                    sum(xx, yy, j, i));
                for (int yy = 1; yy <= i; ++yy)
                for (int xx = x + 1; xx <= j; ++xx)
                    f[j][i][t] = max(f[j][i][t],
                    f[x][y][t - 1] +
                    sum(xx, yy, j, i));
            }
        }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            ans = max(ans, f[j][i][k]);
    cout << ans << '\n';
    return 0;
}