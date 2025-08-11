#include<bits/stdc++.h>
#define int long long
using namespace std;
const int lzj = 1e9 + 7;
int n, h[1205], a[605], cnt[605], ans = 0, h0[1205],
t[605];
bool check() {
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n * 2; ++i)
        ++cnt[h[i]], h0[i] = h[i];
    for (int i = 1; i <= n; ++i)
        if (cnt[i] != 2) return false;
    for (int kk = 1; kk <= n; ++kk)
    for (int i = 1; i <= n * 2; ++i) {
        if (h0[i] == 0) continue;
        int fl = 0;
        for (int j = i + 1; j <= n * 2; ++j)
            if (h0[i] == h0[j]) fl = 1;
        h0[i] -= fl;
    }
    int j = 0;
    for (int i = 1; i <= n * 2; ++i)
        if (h0[i] > 0) t[++j] = i;
    if (j != n) return false;
    for (int i = 1; i <= n; ++i)
        if (t[i] != a[i]) return false;
    return true;
}
void dfs(int now) {
    if (now > 2 * n) {
        if (check()) ans = (ans + 1) % lzj;
        return;
    }
    for (int i = 1; i <= n; ++i)
        h[now] = i, dfs(now + 1);
}
signed main() {
    freopen("ruin.in", "r", stdin);
    freopen("ruin.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + 1 + n);
    dfs(1);
    cout << ans << '\n';
    return 0;
}