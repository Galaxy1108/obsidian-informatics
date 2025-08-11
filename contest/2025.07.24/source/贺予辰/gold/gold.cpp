#include<bits/stdc++.h>
#define int long long
using namespace std;
const int lzj = 1e9 + 7;
int n, k, m[1003][1003], s[1006009], ans = 0;
int cal(int n) {
    int ans = 1;
    do {
        ans *= n % 10;
        n /= 10;
    } while (n);
    return ans;
}
signed main() {
    memset(m, 0, sizeof(m));
    freopen("gold.in", "r", stdin);
    freopen("gold.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            (++m[cal(i)][cal(j)]) %= lzj;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            s[i * n + j] = m[i][j];
    sort(s + n + 1, s + n * n + n + 1);
    for (int i = 0; i < k; ++i)
        ans = (ans + s[n * n + n - i]) % lzj;
    cout << ans << '\n';
    return 0;
}
//10:30 T2 20pts 100 + 20 + 0 + 0 = 120pts
