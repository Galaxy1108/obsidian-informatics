/*
开始思考：8:18

n,m<=3000? 是不是 nm 的 DP
想到一个 n^2m 的 DP 数组
不对，n 是不需要的

Check failed: WA on sample #2

没有去重,当初始序列不同时,是可能出现重复计算的

没说 n<=m
那 m<=n<2*m how calc

这道题的出题人是不是去过缅北

are
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll n, m, mod;
// ll fast_pow(ll a, ll b) {
//     ll anss = 1;
//     while (b) {
//         if (b & 1) {
//             anss = (anss * a) % mod;
//         }
//         a = (a * a) % mod;
//         b >>= 1;
//     }
//     return anss;
// }

ll g[3005][4];
int is_can[3005][3005];

int main() {
    freopen("easyhard.in", "r", stdin);
    freopen("easyhard.out", "w", stdout);
    cin >> n >> m >> mod;
    for (int i = 1;i <= m;i++) {
        int iss_can1 = 0, iss_can2 = 0, iss_can3 = 0, iss_can4 = 0;
        for (int j = 0;j <= n;j++) {
            if (j != n) {
                iss_can1 |= is_can[i - 1][j + 1];
                is_can[i][j] |= (1 << 0);
            }
            if (j != 0) {
                iss_can2 |= is_can[i - 1][j];
                is_can[i][j] |= (1 << 1);
            }
            if (j != 0) {
                iss_can3 |= is_can[i - 1][j - 1];
                is_can[i][j] |= (1 << 2);
            }
            if (j != n) {
                iss_can4 |= is_can[i - 1][j];
                is_can[i][j] |= (1 << 3);
            }
        }
        g[i][0] = ((!!(iss_can1 & (1 << 0))) * g[i - 1][0] + (!!(iss_can1 & (1 << 1))) * g[i - 1][1] + (!!(iss_can1 & (1 << 2))) * g[i - 1][2] + (!!(iss_can1 & (1 << 3))) * g[i - 1][3]) % mod;
        g[i][1] = ((!!(iss_can2 & (1 << 0))) * g[i - 1][0] + (!!(iss_can2 & (1 << 1))) * g[i - 1][1] + (!!(iss_can2 & (1 << 2))) * g[i - 1][2] + (!!(iss_can2 & (1 << 3))) * g[i - 1][3]) % mod;
        g[i][2] = ((!!(iss_can3 & (1 << 0))) * g[i - 1][0] + (!!(iss_can3 & (1 << 1))) * g[i - 1][1] + (!!(iss_can3 & (1 << 2))) * g[i - 1][2] + (!!(iss_can3 & (1 << 3))) * g[i - 1][3]) % mod;
        g[i][3] = ((!!(iss_can4 & (1 << 0))) * g[i - 1][0] + (!!(iss_can4 & (1 << 1))) * g[i - 1][1] + (!!(iss_can4 & (1 << 2))) * g[i - 1][2] + (!!(iss_can4 & (1 << 3))) * g[i - 1][3]) % mod;
        if (i == 1) {
            g[i][0] = g[i][1] = g[i][2] = g[i][3] = 1;
        }
    }
    cout << (g[m][0] + g[m][1] + g[m][2] + g[m][3]) % mod;
    // cout << fast_pow(2, min(n + m, 2 * m));
    return 0;
}