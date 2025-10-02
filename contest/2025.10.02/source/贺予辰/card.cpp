#include<bits/stdc++.h>
using namespace std;
int f[5005][5005][2], n, a, c = 0, cs[5005], m, q;
int solve() {
    memset(f, 0x3f, sizeof(f));
    memset(f[0], 0, sizeof(f[0]));
    for (int i = 1; i <= n; ++i) {
        for (int j = max(i + c - n, 0);
        j <= min(c, i); ++j) {
            if ((cs[i] & 1) || !cs[i])
                f[i][j][1] =
                min(f[i - 1][j - 1][1],
                f[i - 1][j - 1][0] + 1);
            if (((cs[i] & 1) ^ 1))
                f[i][j][0] =
                min(f[i - 1][j][0],
                f[i - 1][j][1] + 1);
        }
    }
    int ans = 2.1e9;
    if ((cs[n] & 1) || !cs[n]) ans = min(ans, f[n][c][1]);
    if (((cs[n] & 1) ^ 1)) ans = min(ans, f[n][c][0]);
    return ans;
}
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    memset(cs, 0, sizeof(cs));
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i)
        cin >> a, c += (a & 1);
    int b, p;
    for (int i = 1; i <= m; ++i)
        cin >> p >> b, cs[p] = b;
    while (q--) {
        int opt, x, y;
        cin >> opt >> x;
        if (opt == 1) cs[x] = 0;
        else cin >> y, cs[x] = y;
        cout << solve() << '\n';
    }
    return 0;
}