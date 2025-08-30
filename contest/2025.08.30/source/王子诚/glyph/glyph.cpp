#include <bits/stdc++.h>
using namespace std;

long long a[305][305];
long long dp[305][305];
long long xa, ya, xb, yb, n, q;

int main() {
    freopen("glyph.in", "r", stdin);
    freopen("glyph.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for (long long i = 1;i <= n;i++) {
        for (long long j = 1;j <= n;j++) {
            cin >> a[i][j];
        }
    }
    while (q--) {
        cin >> xa >> xb >> ya >> yb;
        for (long long i = xa;i <= xb;i++) {
            dp[i][ya - 1] = 0x3f3f3f3f3f3f;
        }
        for (long long i = ya;i <= yb;i++) {
            dp[xa - 1][i] = 0x3f3f3f3f3f3f;
        }
        dp[xa][ya - 1] = 0;
        for (long long i = xa;i <= xb;i++) {
            for (long long j = ya;j <= yb;j++) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
            }
        }
        cout << dp[xb][yb] << '\n';
    }
}