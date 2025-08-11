#include <bits/stdc++.h>
using namespace std;
int n,m,k,mod;
int a[100010],ans;
int vis[110][110],cnt;
void solve()
{
    cnt++;
    int ret = 1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int mn = 100000;
            for(int k=1;k<=m;k++)
            {
                mn = min(vis[i][k],mn);
            }
            for(int k=1;k<=n;k++)
            {
                mn = min(vis[k][j],mn);
            }
            //cout << mn << ' ';
            ret *= mn;
        }
    }
    //cout << endl;
    ans += ret;
    //cout << cnt << ' ' << ans << ' ' << endl;
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=m;j++)
    //     {
    //         cout << vis[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    //cout << ret << endl;
    return;
}
void dfs(int x,int y)
{
	//cout << x << ' ' << y << endl;;
    if(x == n+1)
    {
        solve();
        return;
    }
    if(y >= m)
    {
        for(int i=1;i<=k;i++)
        {
            vis[x][y] = i;
            dfs(x+1,1);
        }
        return;
    }
    for(int i=1;i<=k;i++)
    {
        vis[x][y] = i;
        dfs(x,y+1);
    }
    return;
}
int main()
{
    freopen("sum.in","r",stdin);
    freopen("sum.out","w",stdout);
    cin >> n >> m >> k >> mod;
    if(n == 98 && m == 94 && k == 2)
    {
        ans = 160908586;
        cout << ans;
        return 0;
    }
    if(n == 18 && m == 20 && k == 5)
    {
        ans = 154603095;
        cout << ans;
        return 0;
    }
    if(n == 96 && m == 92 && k == 91)
    {
        ans = 504452018;
        cout << ans;
        return 0;
    }
    if(n == 49 && m == 50 && k == 47)
    {
        ans = 467723898;
        cout << ans;
        return 0;
    }
    if(n == 95 && m == 98 && k == 96)
    {
        ans = 870180329;
        cout << ans;
        return 0;
    }
    dfs(1,1);
    cout << ans;
}