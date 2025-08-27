#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("never.in", "r", stdin);
    freopen("never.out", "w", stdout);
    ll T;
    cin >> T;
    while (T--) {
        ll n, s, t, x, y;
        cin >> n >> s >> t >> x >> y;
        while (n) {
            if (s >= t) {
                ll cnt = ((s - t) / x + 1);
                if (cnt > n) {
                    cnt = n;
                }
                n -= cnt;
                s -= x * cnt;
            } else {
                ll cnt = (t - s) / y + !!((t - s) % y);
                if (cnt > n) {
                    cnt = n;
                }
                n -= cnt;
                s += y * cnt;
            }
        }
        cout << s << '\n';
    }
}