#include<bits/stdc++.h>
using namespace std;
string s[41];
int n, p[81], m;
bool vis[41];
void dfs(int x) {
    if (x > m) {
        for (int i = 1; i <= m; ++i)
            cout << s[p[i]] << '\n';
        exit(0);
    }
    if (p[x]) dfs(x + 1);
    for (int i = n; i; --i) {
        if (p[x + i + 1] || x + i + 1 > m
        || vis[i]) continue;
        p[x + i + 1] = p[x] = i, vis[i] = 1;
        dfs(x + 1);
        p[x + i + 1] = p[x] = vis[i] = 0;
    }
}
int main() {
    freopen("flower.in", "r", stdin);
    freopen("flower.out", "w", stdout);
    memset(p, 0, sizeof(p));
    memset(vis, 0, sizeof(vis));
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n, m = n << 1;
    for (int i = 1; i <= n; ++i)
        cin >> s[i];
    if (n % 4 == 1 || n % 4 == 2) {
        cout << "You have no egg!" << '\n';
        return 0;
    }
    dfs(1);
    return 0;
}