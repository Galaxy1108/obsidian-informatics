#include<bits/stdc++.h>
using namespace std;
const int N = 11;
struct perm {
    int a[N], siz;
    int & operator [] (int p) {
        return a[p];
    }
} p, q, h;
perm inv(perm p) {
    perm ans;
    ans.siz = p.siz;
    for (int i = 1; i <= p.siz; ++i)
        ans[p[i]] = i;
    return ans;
}
perm operator * (perm p, perm q) {
    perm ans;
    ans.siz = p.siz;
    for (int i = 1; i <= p.siz; ++i)
        ans[i] = q[p[i]];
    return ans;
}
bool operator == (perm p, perm q) {
    if (p.siz ^ q.siz) return false;
    for (int i = 1; i <= p.siz; ++i)
        if (p[i] ^ q[i]) return false;
    return true;
}
int n;
bool vis[N];
bool dfs(int x) {
    if (x > n)
        return h * p * inv(h) == q;
    bool fl;
    for (int i = 1; i <= n; ++i)
        if (!vis[i]) {
            vis[i] = 1, h[x] = i;
            if (dfs(x + 1))
                return 1;
            vis[i] = 0;
        }
    return 0;
}
int main() {
    freopen("permutation.in", "r", stdin);
    freopen("permutation.out", "w", stdout);
    memset(vis, 0, sizeof(vis));
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    srand(time(0));
    cin >> n;
    if (n >= N) {
        cout << "NO" << '\n';
        return 0;
    }
    p.siz = q.siz = h.siz = n;
    for (int i = 1; i <= n; ++i)
        cin >> p[i];
    for (int i = 1; i <= n; ++i)
        cin >> q[i];
    if (dfs(1)) {
        cout << "YES" << '\n';
        for (int i = 1; i <= n; ++i)
            cout << h[i] << ' ';
    } else cout << "NO" << '\n';
    return 0;
}