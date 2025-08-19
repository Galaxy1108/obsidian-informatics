#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9, pr[22] =
{0, 100, 100, 97, 96, 95, 90, 85, 80, 82, 78, 75,
70, 65, 55, 50, 15, 12, 10, 8, 5, 2}, sn = 15;
int n, w[8005], u[8005], t[8005], f[25006][25],
tmp[25];
int main() {
    freopen("sniper.in", "r", stdin);
    freopen("sniper.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    memset(f, -0x3f, sizeof(f));
    memset(f[0], 0, sizeof(f[0]));
    cin >> n;
    w[0] = u[0] = t[0] = 0;
    for (int i = 1; i <= n; ++i)
        cin >> w[i] >> u[i] >> t[i];
    int nw = 0;
    for (int i = 0; i <= 25002; ++i) {
        int fl = 0;
        memcpy(tmp, f[i], sizeof(tmp));
        for (int j = 1; j <= 20; ++j) {
            f[i][j] = max(f[i][j], max(tmp[j + 1],
            tmp[j - 1]));
            f[i][j] = max(f[i][j], tmp[j + 2]);
            if (j > 2) f[i][j] = max(f[i][j],
                tmp[j - 2]);
        }
        while (nw < n && t[nw + 1] == i) {
            ++nw;
            f[i + 2][u[nw]] = max(f[i + 2][u[nw]],
            f[i][u[nw]] + pr[w[nw]]);
            if (w[nw] == sn) fl = u[nw];
        }
        if (fl) {
            memset(f[i + 2], -0x3f,sizeof(f[i + 2]));
            f[i + 2][fl] =
            max(f[i + 2][fl], f[i][fl] + 50);
            memset(f[i], -0x3f, sizeof(f[i]));
            memset(f[i + 1], -0x3f,sizeof(f[i + 1]));
        } else {
            for (int j = 1; j <= 20; ++j)
                f[i + 1][j] = max(f[i+1][j],f[i][j]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= 20; ++i)
        ans = max(ans, max(f[25001][i],
            max(f[25002][i], f[25003][i])));
    cout << ans << '\n';
    return 0;
}
