#include<bits/stdc++.h>
using namespace std;
int n, q[100005], p[100005], h[100005];
vector<int> qq[100005], pp[100005];
int cq = 0, cp = 0;
bool vis[100005];
bool cmp(vector<int> a, vector<int> b) {
    return a.size() < b.size();
}
bool work() {
    if (cp ^ cq) return 0;
    for (int i = 1; i <= cp; ++i) {
        if (qq[i].size() != pp[i].size())
            return 0;
        for (int j = 0; j < qq[i].size(); ++j)
            h[qq[i][j]] = pp[i][j];
    }
    return 1;
}
int main() {
    freopen("permutation.in", "r", stdin);
    freopen("permutation.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> p[i];
    for (int i = 1; i <= n; ++i)
        cin >> q[i];
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; ++i)
        if (vis[i] ^ 1) {
            int u = i; ++cp;
            while (!vis[u]) {
                vis[u] = 1;
                pp[cp].push_back(u);
                u = p[u];
            }
        }
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; ++i)
        if (vis[i] ^ 1) {
            int u = i; ++cq;
            while (!vis[u]) {
                vis[u] = 1;
                qq[cq].push_back(u);
                u = q[u];
            }
        }
    sort(qq + 1, qq + 1 + cq, cmp);
    sort(pp + 1, pp + 1 + cp, cmp);
    if (work()) {
        cout << "YES" << '\n';
        for (int i = 1; i <= n; ++i)
            cout << h[i] << ' ';
    } else cout << "NO" << '\n';
    return 0;
}