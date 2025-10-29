#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
using ll = long long;

const ll inf = 0x7f7f7f7f7f7f7f7f;
int n, m;
int a[200010], l[200010], r[200010];
vector<int> v[200010];
ll minn = inf;

void dfs(int x)
{
    if (x == m + 1)
    {
        ll mn, mx, sum = 0;
        for (int i = 1; i <= n; i++)
        {
            if(v[i].empty()) continue;
            mn = inf, mx = -inf;
            for (int t: v[i])
            {
                if (r[t] < a[i]) mn = min(mn, 1ll * r[t]);
                if (l[t] > a[i]) mx = max(mx, 1ll * l[t]);
            }
            if (mn == inf) sum += mx - a[i];
            else if (mx == -inf) sum += a[i] - mn;
            else sum += min(a[i] + mx - 2ll * mn, 2ll * mx - a[i] - mn);
        }
        minn = min(minn, sum);
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        v[i].push_back(x);
        dfs(x + 1);
        v[i].pop_back();
    }
}

int main()
{
    freopen("points.in", "r", stdin);
    freopen("points.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int i = 1; i <= m; i++) scanf("%d%d", l + i, r + i);
    dfs(1);
    printf("%lld\n", minn);
    return 0;
}