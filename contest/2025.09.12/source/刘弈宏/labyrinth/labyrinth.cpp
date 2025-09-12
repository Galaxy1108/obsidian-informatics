#include <bits/stdc++.h>
using namespace std;

const int maxn = 4e5 + 5;
vector<int> G[maxn];
int a[maxn], f[maxn], n, t, ans = 0;

void dfs(int x, int fa)
{
    int s = 0, p = 0;
    for (auto y : G[x])
    {
        if (y == fa)
            continue;
        dfs(y, x);
        for (int i = 0; i <= 20; i++)
        {
            if (((s >> i) & 1) && ((f[y] >> i) & 1))
                p = max(p, i + 1);
        }
        s |= f[y];
    }
    while (((s >> p) & 1))
        p++;
    ans = max(ans, p);
    f[x] = s | ((1 << (p + 1)) - 1);
    f[x] = f[x] ^ ((1 << p) - 1);
    return;
}

void solve()
{
    for (int i = 2; i <= n; i++)
    {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v), G[v].push_back(u);
    }
    ans = 0;
    dfs(1, 0);
    cout << ans + 1 << endl;
}

int main()
{
    freopen("labyrinth.in", "r", stdin);
    freopen("labyrinth.out", "w", stdout);
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i <= n; i++)
            G[i].clear(), a[i] = 0, f[i] = 0;
        solve();
    }
    return 0;
}
