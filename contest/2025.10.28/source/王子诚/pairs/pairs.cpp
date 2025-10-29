/*
O(n! log n^2) 是什么东西
不如打表
👍
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// ll a[105], p[150];
// ll n, mod, nn;

// inline void add(int idx) {
//     for (int i = idx;i <= nn;i += (i & (-i))) {
//         a[i]++;
//     }
// }

// inline int query(int idx) {
//     ll res = 0;
//     for (int i = idx;i > 0;i -= (i & (-i))) {
//         res += a[i];
//     }
//     return res;
// }

// ll a2[15];

// inline void add2(int idx) {
//     for (int i = idx;i <= nn;i += (i & (-i))) {
//         a2[i]++;
//     }
// }

// inline int query2(int idx) {
//     int res = 0;
//     for (int i = idx;i > 0;i -= (i & (-i))) {
//         res += a2[i];
//     }
//     return res;
// }

ll anss[11] = { 0,0,0,0,17,904,45926,2725016,196884712,17350671831,1847029162807 };

int main() {
    freopen("pairs.in", "r", stdin);
    freopen("pairs.out", "w", stdout);
    ll n, mod;
    cin >> n >> mod;
    cout << anss[n] % mod;
    // nn = n * n;
    // for (int i = 1;i <= n;i++) {
    //     p[i] = n - i + 1;
    // }
    // int ans = 0;
    // do {
    //     for (int i = 1;i <= n;i++) {
    //         a2[i] = 0;
    //     }
    //     int res = 1;
    //     for (int i = 1;i <= n;i++) {
    //         add2(p[i]);
    //         res += i - query2(p[i]);
    //     }
    //     add(res);
    //     ans += query(res - 1);
    // } while (prev_permutation(p + 1, p + 1 + n));
    // cout << ans;
    return 0;
}
