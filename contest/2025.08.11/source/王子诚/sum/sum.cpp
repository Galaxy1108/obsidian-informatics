#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    freopen("sum.in", "r", stdin);
    freopen("sum.out", "w", stdout);
    ll T;
    cin >> T;
    while (T--) {
        ll s, k;
        cin >> s >> k;
        cout << ((k > s / 2) ? -1 : 2 * k) << '\n';
    }
}