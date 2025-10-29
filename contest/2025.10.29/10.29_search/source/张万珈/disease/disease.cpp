#include <bits/stdc++.h>
using namespace std;
const int N = 310;
vector<int> e[N];
int fa[N];
bool vis[N];
void dfs(int u,int f)
{
    fa[u] = f;
    for(int v:e[u])
    {
        if(v == f) continue;
        dfs(v,u);
    }
}
int ans = N+1;
int n,m;
void solve(int siz,int sum)
{
    if(sum >= ans) return;
    if(siz == 0)
    {
        ans = min(ans,sum);
        return;
    }
    vector<int> s;
    for(int i=1;i<=n;i++)
    {
        if(vis[i])
        {
            s.push_back(i);
            vis[i] = 0;
        }
    }
    vector<int> son;
    siz=0;
    for(int u:s)
    {
        for(int v:e[u])
        {
            if(v==fa[u]) continue;
            vis[v] = 1;
            son.push_back(v);
            siz++;
        }
    }
    sum += siz;
    if(siz == 0)
    {
        ans = min(ans,sum);
        return;
    }
    for(int x:son)
    {
        vis[x] = 0;
        solve(siz-1,sum-1);
        vis[x] = 1;
    }
    for(int x:son) vis[x] = 0;
    for(int x:s) vis[x] = 1;
}
int main()
{
    freopen("disease.in","r",stdin);
    freopen("disease.out","w",stdout);
    cin >> n >> m;
    for(int i=1,u,v;i<=m;i++)
    {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1,0);
    vis[1] = 1;
    solve(1,1);
    cout << ans;
}