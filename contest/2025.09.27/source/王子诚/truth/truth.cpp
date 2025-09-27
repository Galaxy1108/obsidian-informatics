#include <bits/stdc++.h>
using namespace std;

int a[50005];
int dp[50005][30];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("truth.in", "r", stdin);
    freopen("truth.out", "w", stdout);
    int n, k, m;
    cin >> n >> k >> m;
    for (int i = 1;i <= k;i++) {
        dp[0][i] = 1;
    }
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        for (int j = 1;j <= k;j++) {
            dp[i][j] = dp[i - 1][j] + 1;
        }
        dp[i][a[i]] = 1;
    }
    while (m--) {
        int opt;
        cin >> opt;
        if (opt == 1) {
            int p, v;
            cin >> p >> v;
            int da = a[p], db = v;
            a[p] = v;
            for (int i = 1;i <= n;i++) {
                dp[i][da] = dp[i - 1][da] + 1;
                dp[i][db] = dp[i - 1][db] + 1;
                dp[i][a[i]] = 1;
            }
        } else {
            int anss = INT_MAX;
            for (int i = 1;i <= n;i++) {
                int res = INT_MIN;
                for (int j = 1;j <= k;j++) {
                    res = max(res, dp[i][j]);
                }
                if (res == i + 1) {
                    continue;
                }
                anss = min(anss, res);
            }
            cout << (anss == INT_MAX ? -1 : anss)  << '\n';
        }
    }
}