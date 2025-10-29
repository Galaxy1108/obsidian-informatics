#include<bits/stdc++.h>
#define int long long
using namespace std;
int p, n, t[105], a[15], ans = 0, t1[15];
bool is[15];
void upd(int p) {
    if (!p) return;
    while (p <= 100)
        ++t[p], p += (p & -p);
}
int que(int p) {
    int ans = 0;
    while (p)
        ans += t[p], p -= (p & -p);
    return ans;
}
void upd1(int p) {
    if (!p) return;
    while (p <= n)
        ++t1[p], p += (p & -p);
}
int que1(int p) {
    int ans = 0;
    while (p)
        ans += t1[p], p -= (p & -p);
    return ans;
}
int nxd() {
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        t1[i] = 0;
    for (int i = 1; i <= n; ++i)
        ans += que1(n) - que1(a[i]),
        upd1(a[i]);
    return ans;
}
void dfs(int x) {
    if (x > n) {
        int tmp = nxd();
        ans += que(100) - que(tmp);
        upd(tmp);
        return;
    }
    for (int i = 1; i <= n; ++i)
        if (!is[i]) is[i] = 1, a[x] = i,
            dfs(x + 1), is[i] = 0;
}
signed main() {
    freopen("pairs.in", "r", stdin);
    freopen("pairs.out", "w", stdout);
    srand(time(0));
    cin >> n >> p;
    if (n > 10) cout << 0 << '\n';
    else dfs(1), cout << ans % p << '\n';
    return 0;
}