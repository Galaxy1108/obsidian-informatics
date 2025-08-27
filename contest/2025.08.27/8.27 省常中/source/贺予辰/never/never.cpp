#include<bits/stdc++.h>
#define int long long
using namespace std;
int t;
int N, X, Y, S, T;
signed main() {
    freopen("never.in", "r", stdin);
    freopen("never.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> N >> S >> T >> X >> Y;
        if (X == Y) {
            if (S < T) {
                int k = (T - S + Y - 1) / Y;
                if (N <= k) {
                    cout << S + Y * N << '\n';
                    continue;
                }
                N -= k;
                S += Y * k;
            } else {
                int k = (S - T) / X;
                if (N <= k) {
                    cout << S - X * N << '\n';
                    continue;
                }
                N -= k;
                S -= X * k;
            }
            if (N & 1) cout << S - X << '\n';
            else cout << S << '\n';
            continue;
        }
        while (N--) {
            if (S < T) S += Y;
            else S -= X;
        }
        cout << S << '\n';
    }
    return 0;
}