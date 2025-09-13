#include<bits/stdc++.h>
#define int long long
using namespace std;
const int p = 998244353;
int n, k, t;
signed main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> k >> t;
    while (t--) {
        cin >> n;
        if (k > (n / 2)) {
            cout << n << ' ' << 1 << '\n';
            continue;
        }
        cout << n * n % p << n % p << '\n';
    }
    return 0;
}