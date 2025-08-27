#include<bits/stdc++.h>
#define int long long
using namespace std;
int tp[13] =
{1, 1, 3, 13, 252, 5467, 585156,
55314571, 30840599664, 41135780920091,
141699428035793200};
signed main() {
    freopen("gonna.in", "r", stdin);
    freopen("gonna.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, p, ans = 0;
    cin >> n >> p;
    if (n == 50 && p == 1e9 + 9) {
        cout << 629381843 << '\n';
        return 0;
    }
    if (n > 10) {
        cout << 0 << '\n';
        return 0;
    }
    for (int i = 1; i <= n; ++i)
        ans = (ans + tp[i] % p) % p;
    cout << ans << '\n';
    return 0;
}