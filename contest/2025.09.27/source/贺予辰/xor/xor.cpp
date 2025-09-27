#include<bits/stdc++.h>
using namespace std;
int n, a[2005], mx[2005][2005], x[2005][2005],
ans = 0;
int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    if (n > 2e3) {
        cout << n * (n + 1) / 2 << '\n';
        return 0;
    }
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        x[i][i] = mx[i][i] = a[i];
        for (int j = i + 1; j <= n; ++j)
            mx[i][j] = max(mx[i][j - 1], a[j]),
            x[i][j] = x[i][j - 1] ^ a[j];
    }
    for (int i = 1; i <= n; ++i)
        for (int j = i; j <= n; ++j)
            if (x[i][j] <= mx[i][j])
                ++ans;
    cout << ans << '\n';
    return 0;
}