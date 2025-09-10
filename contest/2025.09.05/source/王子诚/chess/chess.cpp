#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define mod 9999973

ll dp[105][105][105];
ll n, m;

#define k0(ks) (m - (ks))
#define k1(ks,k2) ((ks) - (k2))
#define c2(n) (((n) * (n-1)) / 2)


int main() {
    freopen("chess.in", "r", stdin);
    freopen("chess.out", "w", stdout);
    cin >> n >> m;
    dp[0][0][0] = 1;
    for (int i = 1;i <= n;i++) {
        for (int ks = 0;ks <= m;ks++) {
            for (int k2 = 0;k2 <= ks;k2++) {
                // 0 个棋
                dp[i][ks][k2] = dp[i - 1][ks][k2];
                // 1 个棋
                if (k2 >= 1) {
                    dp[i][ks][k2] = dp[i][ks][k2] + (dp[i - 1][ks][k2 - 1] * k1(ks, k2 - 1) % mod) % mod;
                }
                if (ks >= 1 && ks - 1 >= k2) {
                    dp[i][ks][k2] = dp[i][ks][k2] + (dp[i - 1][ks - 1][k2] * k0(ks - 1) % mod) % mod;
                }
                // 2 个棋
                if (ks >= 2 && ks - 2 >= k2) {
                    dp[i][ks][k2] = dp[i][ks][k2] + (dp[i - 1][ks - 2][k2] * c2(k0(ks - 2)) % mod) % mod;
                }
                if (ks >= 1 && k2 >= 1) {
                    dp[i][ks][k2] = dp[i][ks][k2] + (dp[i - 1][ks - 1][k2 - 1] * (k0(ks - 1) * k1(ks - 1, k2 - 1) % mod) % mod) % mod;
                }
                if (k2 >= 2) {
                    dp[i][ks][k2] = dp[i][ks][k2] + (dp[i - 1][ks][k2 - 2] * c2(k1(ks, k2 - 2)) % mod) % mod;
                }
            }
        }
    }
    ll anss = 0;
    for (int ks = 0;ks <= m;ks++) {
        for (int k2 = 0;k2 <= ks;k2++) {
            anss += dp[n][ks][k2];
            anss %= mod;
        }
    }
    cout << anss;
    return 0;
}
