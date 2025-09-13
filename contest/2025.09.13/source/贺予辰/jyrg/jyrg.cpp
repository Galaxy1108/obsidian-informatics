#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, a[100005], t;
bool pd(int n) {
    for (int i = 1; i < n; ++i)
        if (a[i] < a[i + 1]) return 0;
    return 1;
}
signed main() {
    freopen("jyrg.in", "r", stdin);
    freopen("jyrg.out", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        if (pd(n)) cout << 0 << '\n';
        else cout << -1 << '\n';
    }
    return 0;
}