#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll dp[205][205][205][3];
ll idx[205][3];
ll cnt_pre[205][3][3];
ll cnt[3];

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    string str;
    cin >> str;
    int sizes = str.size();
    int maxs = sizes / 2 + (sizes % 2);
    str = " " + str;
    for (int i = 1;i <= sizes;i++) {
        int num = str[i] - '0';
        idx[++cnt[num]][num] = i;
        cnt_pre[cnt[num]][num][0] = cnt[0];
        cnt_pre[cnt[num]][num][1] = cnt[1];
        cnt_pre[cnt[num]][num][2] = cnt[2];
        if (cnt[num] > maxs) {
            cout << -1;
            return 0;
        }
    }
    for (ll c0 = 0;c0 <= cnt[0];c0++) {
        for (ll c1 = 0;c1 <= cnt[1];c1++) {
            for (ll c2 = 0;c2 <= cnt[2];c2++) {
                dp[c0][c1][c2][0] = INT_MAX;
                dp[c0][c1][c2][1] = INT_MAX;
                dp[c0][c1][c2][2] = INT_MAX;
            }
        }
    }
    dp[0][0][0][0] = dp[0][0][0][1] = dp[0][0][0][2] = 0;
    for (ll c0 = 0;c0 <= cnt[0];c0++) {
        for (ll c1 = 0;c1 <= cnt[1];c1++) {
            for (ll c2 = 0;c2 <= cnt[2];c2++) {
                if (c0 != 0) {
                    dp[c0][c1][c2][0] = min(dp[c0][c1][c2][0], dp[c0 - 1][c1][c2][1] + idx[c0][0] - ((c0 - 1) + min(cnt_pre[c0][0][1], c1) + min(cnt_pre[c0][0][2], c2)) - 1);
                    dp[c0][c1][c2][0] = min(dp[c0][c1][c2][0], dp[c0 - 1][c1][c2][2] + idx[c0][0] - ((c0 - 1) + min(cnt_pre[c0][0][1], c1) + min(cnt_pre[c0][0][2], c2)) - 1);
                }
                if (c1 != 0) {
                    dp[c0][c1][c2][1] = min(dp[c0][c1][c2][1], dp[c0][c1 - 1][c2][0] + idx[c1][1] - (min(cnt_pre[c1][1][0], c0) + (c1 - 1) + min(cnt_pre[c1][1][2], c2)) - 1);
                    dp[c0][c1][c2][1] = min(dp[c0][c1][c2][1], dp[c0][c1 - 1][c2][2] + idx[c1][1] - (min(cnt_pre[c1][1][0], c0) + (c1 - 1) + min(cnt_pre[c1][1][2], c2)) - 1);
                }
                if (c2 != 0) {
                    dp[c0][c1][c2][2] = min(dp[c0][c1][c2][2], dp[c0][c1][c2 - 1][0] + idx[c2][2] - (min(cnt_pre[c2][2][0], c0) + min(cnt_pre[c2][2][1], c1) + (c2 - 1)) - 1);
                    dp[c0][c1][c2][2] = min(dp[c0][c1][c2][2], dp[c0][c1][c2 - 1][1] + idx[c2][2] - (min(cnt_pre[c2][2][0], c0) + min(cnt_pre[c2][2][1], c1) + (c2 - 1)) - 1);
                }
            }
        }
    }
    ll ans = min({ dp[cnt[0]][cnt[1]][cnt[2]][0], dp[cnt[0]][cnt[1]][cnt[2]][1], dp[cnt[0]][cnt[1]][cnt[2]][2] });
    cout << (ans == INT_MAX ? -1 : ans);
}