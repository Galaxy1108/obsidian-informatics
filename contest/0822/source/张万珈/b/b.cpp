#include <bits/stdc++.h>
using namespace std;
int mp[2010][2010];
int mn[2010],id[2010];
int fa[2010];
bool vis[2010];
int n;
int ans=INT_MAX,rt,fans[2010];
vector<int> son[2010];
void count()
{
    for(int i=1;i<=n;i++)mn[i] = INT_MAX;
    int res=0;
    // for(int i=1;i<=n;i++)cout << fa[i] << ' ' << id[i] << endl;
    for(int i=2;i<=n;i++)
    {
        // cout << id[i] << ' ' << id[fa[i]] << '\n';
        mn[id[i]] = min(mn[id[fa[i]]],mp[id[fa[i]]][id[i]]);
        res += mn[id[i]];
    }
//    cout << "OKQWQ";
    ans = min(ans,res);
    // cout << ans << endl << endl;
}
void dfs(int now)
{
    if(now == n+1)
    {
        count();
        return;
    }
    for(int i=1;i<now;i++)
    {
        if(i==now)continue;
        fa[now] = i;
        dfs(now+1);
    }
}
void solve()
{
    // memset(vis,0,sizeof(vis));
    dfs(2);
}
void dfs1(int now)
{
    if(now == n+1)
    {
        solve();
        fans[id[1]] = min(fans[id[1]],ans);
        ans = INT_MAX;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            vis[i] = 1;
            id[now] = i;
            dfs1(now+1);
            vis[i] = 0;
        }
    }
}
int main()
{
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    cin >> n;
    for(int i=1;i<n;i++)
    {
        id[i] = i;
        mp[i][i] = 0;
        for(int j=i+1;j<=n;j++)
        {
            cin >> mp[i][j];
            mp[j][i] = mp[i][j];
        }
    }
    id[n]=n;
    for(int i=1;i<=n;i++)
    {
        fans[i] = INT_MAX;
    }
    dfs1(1);
    for(int i=1;i<=n;i++)
    {
        cout << fans[i] << endl;
    }
}
