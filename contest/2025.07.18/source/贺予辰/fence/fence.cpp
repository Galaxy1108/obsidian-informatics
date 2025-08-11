#include<bits/stdc++.h>
#define int long long
using namespace std;
const int xxy = 1e9 + 7;
int n, w = 0, t;
int main() {
    freopen("fence.in", "r", stdin);
    freopen("fence.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> t;
    for (int i = 1; i <= n; ++i) cin >> t, w = (w + t) % xxy;
    int ans = 1;
    for (int i = 1; i <= w; ++i) ans = ans * i % xxy;
    cout << ans << endl;
    return 0;
}