#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll dp[10000][10000];
ll a[10000], b[10000];

int main() {
    freopen("kyoto.in", "r", stdin);
    freopen("kyoto.out", "w", stdout);
    ll h, w;
    cin >> h >> w;
    for (int i = 1;i <= h;i++) {
        cin >> a[i];
    }
    for (int i = 1;i <= w;i++) {
        cin >> b[i];
    }
    for (int i = 1;i <= h;i++) {
        for (int j = 1;j <= w;j++) {
            if (i != 1 && j != 1) {
                dp[i][j] = min(dp[i][j - 1] + a[i], dp[i - 1][j] + b[j]);
                continue;
            }else if (i == 1 && j != 1) {
                dp[i][j] = dp[i][j - 1] + a[i];
            }else if (i != 1 && j == 1) {
                dp[i][j] = dp[i - 1][j] + b[j];
            }
        }
    }
    cout << dp[h][w];
    return 0;
}