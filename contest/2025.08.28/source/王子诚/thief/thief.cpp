#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll a[500005];

int main() {
    freopen("thief.in", "r", stdin);
    freopen("thief.out", "w", stdout);
    ll n, m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    while (m--) {
        int l, r, c;
        cin >> l >> r >> c;
        for (int i = l;i <= r;i++) {
            if (c < a[i]) {
                c++;
            }
            if (c > a[i]) {
                c--;
            }
        }
        cout << c << '\n';
    }
}