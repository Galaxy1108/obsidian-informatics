#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    freopen("matrixcascade.in", "r", stdin);
    freopen("matrixcascade.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, t, x, y;
    cin >> t;
    while (t--) {
        cin >> n >> x >> y;
        if ((x + y) > (n * n * n * n / 2)) {
            cout << "NO" << '\n';
            continue;
        } 
        cout << "YES" << '\n';
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j <= n; ++j)
                cout << i * n + j << ' ';
            cout << '\n';
        }
    }
    return 0;
}