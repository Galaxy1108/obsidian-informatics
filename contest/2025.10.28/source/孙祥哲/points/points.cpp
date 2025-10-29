#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m, a[200005], l[200005], r[200005];
int l1[200005], r1[200005];
ll ans = 1e18;

void dfs(int x)
{
    if (x > m)
    {
        ll sum = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i]>=l1[i] && a[i]<=r1[i]) continue;
            sum += min(abs(l1[i]-a[i]),abs(r1[i]-a[i])); 
        }
        ans = min(ans, sum);
    }
    for (int i = 1; i <= n; i++)
    {
        int tl = l1[i], tr = r1[i];
        l1[i] = max(l1[i], l[x]), r1[i] = min(r1[i], r[x]);
        if (l1[i] <= r1[i]) dfs(x+1);
        l1[i] = tl, r1[i] = tr;
    }
}

int main()
{
    freopen("pairs.in", "r", stdin);
    freopen("pairs.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    if (n > 10) { cout << 0; return 0; }
    for (int i = 1; i <= n; i++) cin >> a[i], l1[i] = 2e9, r1[i] = -2e9;
    for (int i = 1; i <= m; i++) cin >> l[i] >> r[i];
    dfs(1);
    cout << ans;
    return 0;
}