#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll a[200005];

int main() {
    freopen("easy.in", "r", stdin);
    freopen("easy.out", "w", stdout);
    ll n, q;
    cin >> n >> q;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    while (q--) {
        ll opt;
        cin >> opt;
        if (opt == 1) {
            ll v;
            cin >> v;
            for (int i = 1;i <= n;i++) {
                a[i] = min(a[i], v);
            }
        } else if (opt == 2) {
            for (int i = 1;i <= n;i++) {
                a[i] += i;
            }
        } else if (opt == 3) {
            ll l, r;
            cin >> l >> r;
            ll sum = 0;
            for (int i = l;i <= r;i++) {
                sum += a[i];
            }
            cout << sum << '\n';
        }
    }
}