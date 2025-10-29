#include<bits/stdc++.h>
using namespace std;
struct perm {
    int siz, a[6];
    int & operator [] (int p) {
        return a[p];
    }
} t, l[100005];
bool operator == (perm a, perm b) {
    if (a.siz ^ b.siz) return 0;
    for (int i = 1; i <= a.siz; ++i)
        if (a[i] ^ b[i]) return 0;
    return 1;
}
int a[15], ans, n, b[15];
bool is[15];
void dfs(int x) {
    if (x > n) {
        for (int i = 1; i <= (n >> 1); ++i)
            t[i] = min(b[i << 1], b[(i << 1) - 1]);
        for (int i = 1; i <= ans; ++i)
            if (t == l[i]) return;
        l[++ans] = t;
        return;
    }
    if (a[x] != -1) return dfs(x + 1);
    for (int i = 1; i <= n; ++i)
        if (!is[i])
            b[x] = i, is[i] = 1,
            dfs(x + 1), is[i] = 0;
}
int main() {
    freopen("permutation.in", "r", stdin);
    freopen("permutation.out", "w", stdout);
    cin >> n, t.siz = n, n <<= 1;
    if (n > 10) {
        cout << 0 << '\n';
        return 0;
    }
    for (int i = 1; i <= n; ++i)
        cin >> a[i], b[i] = a[i];
    for (int i = 1; i <= n; ++i)
        if (a[i] != -1) is[a[i]] = 1;
    dfs(1);
    cout << ans << '\n';
    return 0;
}