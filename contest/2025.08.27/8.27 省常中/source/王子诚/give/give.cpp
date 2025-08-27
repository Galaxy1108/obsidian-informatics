#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;

ll a[205];
ull dp[2005][5005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("give.in", "r", stdin);
    freopen("give.out", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        int m, s, n;
        cin >> m >> s >> n;
        for (int i = 1;i <= n;i++) {
            cin >> a[i];
        }
        dp[0][0] = 1;
        for (int i = 1;i <= m;i++) {
            for (int j = 0;j <= s;j++) {
                dp[i][j] = 0;
                for (int k = 1;k <= n;k++) {
                    if (j - a[k] < 0) {
                        break;
                    }
                    dp[i][j] += dp[i - 1][j - a[k]];
                    dp[i][j] = (dp[i][j] == 2 ? 0 : dp[i][j]);
                }
            }
        }
        cout << dp[m][s] << '\n';
    }
}