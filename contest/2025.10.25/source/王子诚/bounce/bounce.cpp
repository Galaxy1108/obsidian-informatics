#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

__gnu_pbds::tree<
    int, __gnu_pbds::null_type,
    less<int>, __gnu_pbds::rb_tree_tag,
    __gnu_pbds::tree_order_statistics_node_update
>
trr;

bool vis[25];
int dp[1000005][25];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("bounce.in", "r", stdin);
    freopen("bounce.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    for (int j = 1;j <= 20;j++) {
        dp[1][j] = 1;
    }
    for (int i = 2;i <= n;i++) {
        for (int j = 2;j <= 20;j++) {
            int k = ((i - 1) / j) + 1;
            int idx = (i - k - dp[i - k][j] + 1);
            dp[i][j] = idx + (idx - 1) / (j - 1) + 1;
        }
    }
    for (int i = 1;i <= n;i++) {
        trr.insert(i);
    }
    while (q--) {
        int tp, m;
        cin >> tp >> m;
        if (tp == 1) {
            if (vis[m]) {
                continue;
            }
            for (int i = 1;i <= n;i += m) {
                trr.erase(i);
            }
            vis[m] = true;
        } else if (tp == 2) {
            int l = trr.size();
            for (int i = 1, c = 0;i <= l;i += m, c++) {
                trr.erase(trr.find_by_order(i - 1 - c));
            }
        } else {
            int l = trr.size();
            cout << (l ? *trr.find_by_order(dp[l][m] - 1) : -1) << '\n';
        }
    }
}
