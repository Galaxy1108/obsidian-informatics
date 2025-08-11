#include<bits/stdc++.h>
#define int long long
using namespace std;
int t, s, k;
signed main() {
	freopen("sum.in", "r", stdin);
    freopen("sum.out", "w", stdout); 
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> s >> k;
        if (s % 2ll) {
            if ((k << 1) < s)
                cout << (k << 1) << '\n';
            else cout << -1 << '\n';
        } else cout << -1 << '\n';
    }
    return 0;
}
