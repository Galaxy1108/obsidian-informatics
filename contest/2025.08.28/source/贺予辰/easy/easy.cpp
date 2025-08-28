#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, a[200005], op, l, r, v, q;
int min(int a, int b) {
    return a < b ? a : b;
}
signed main() {
    freopen("easy.in", "r", stdin);
    freopen("easy.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    cin >> q;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= q; ++i) {
        cin >> op;
        if (op == 1) {
            cin >> v;
            for (int i = 1; i <= n; ++i)
                a[i] = min(a[i], v);
        } else if (op == 2)
            for (int i = 1; i <= n; ++i)
                a[i] += i;
        else {
            cin >> l >> r;
            int ans = 0;
            for (int i = l; i <= r; ++i)
                ans += a[i];
            cout << ans << '\n';
        }
    }
    return 0;
}