#include <bits/stdc++.h>
using namespace std;
mt19937 rd(time(0));
struct node{
    long long now=0,sum=0;
};
vector<int> e[510];
int n,k;
int a[510],fa[510];
int s[510];
long long dp[510];
bool vis[510];
long long ans;
void dfs(int u,int f)
{
    fa[u] = f;
    for(int v:e[u])
    {
        if(v == f) continue;
        dfs(v,u);
    }
}
void dfs1(int u)
{
    dp[u] = a[u];
    for(int v:e[u])
    {
        if(v == fa[u]) continue;
        dfs1(v);
        if(!vis[v]) 
        {
            dp[u] = __gcd(dp[u],dp[v]);
        }
    }
}
void solve()
{
    for(int i=1;i<=k;i++)
    {
        vis[s[i]] = 1;
    }
    dfs1(1);
    long long sum=0;
    for(int i=1;i<=k;i++)
    {
        sum += dp[s[i]];
        vis[s[i]] = 0;
    }
    sum += dp[1];
    ans = max(ans,sum);
    return;
}

int main()
{
    freopen("plan.in","r",stdin);
    freopen("plan.out","w",stdout);
    cin >> n >> k;
    for(int i=1,x,y;i<n;i++)
    {
        cin >> x >> y;
        s[i] = i+1;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    dfs(1,0);
    for(int i=1;i<=8e4;i++)
    {
        shuffle(s+1,s+n,rd);
        solve();
    }
    cout << ans;
}