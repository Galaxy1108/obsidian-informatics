#include <bits/stdc++.h>
using namespace std;

int a[200005];
long long dp[200005][5];

int main() {
    freopen("walk.in", "r", stdin);
    freopen("walk.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for (int i = 1;i <= n;i++) {
        dp[i][0] = dp[i - 1][0] + a[i];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + (a[i] % 2) + 2 * (a[i] == 0);
        dp[i][2] = min({ dp[i - 1][0],dp[i - 1][1],dp[i - 1][2] }) + !(a[i] % 2);
        dp[i][3] = min({ dp[i - 1][0],dp[i - 1][1],dp[i - 1][2],dp[i - 1][3] }) + (a[i] % 2) + 2 * (a[i] == 0);
        dp[i][4] = min({ dp[i - 1][0],dp[i - 1][1],dp[i - 1][2],dp[i - 1][3],dp[i - 1][4] }) + a[i];
    }
    cout << min({ dp[n][0],dp[n][1],dp[n][2],dp[n][3],dp[n][4] });
    return 0;
}
