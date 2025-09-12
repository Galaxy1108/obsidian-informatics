#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int SIZE = 1<<21;
const int MAXN = 2e5 + 12;
char buf[SIZE+1],*iS,*iT;
inline char mget()
{
    if (iS==iT) iS = buf,iT = buf + fread(buf,1,SIZE,stdin),*iT = 'E';
    return *(iS++);
}
inline int read()
{
    int x = 0;
    char ch = mget();
    while (ch<'0'||ch>'9') ch = mget();
    while ('0'<=ch&&ch<='9') x = x*10 + ch - '0',ch = mget();
    return x;
}
int n;
int head[MAXN],to[MAXN<<1],nxt[MAXN<<1],cnt;
inline void add(int u,int v)
{
    cnt++;
    to[cnt] = v;
    nxt[cnt] = head[u];
    head[u] = cnt;
}
int sum[MAXN],wt[MAXN],m,vis[MAXN];
int dfs(int u,int f)
{
    wt[u] = 0;
    sum[u] = 1;
    int res = 0;
    for (int i=head[u];i;i=nxt[i])
    {
        int v = to[i];
        if (v==f||vis[v]) continue ;
        int cur = dfs(v,u);
        if (res==0||wt[cur]<wt[res]) res = cur;
        sum[u] += sum[v];
        wt[u] = max(wt[u],sum[v]);
    }
    wt[u] = max(wt[u],m-sum[u]);
    if (res==0||wt[u]<wt[res]) res = u;
    return res;
}
int solve(int rt,int sz)
{
    if (sz==1) return 1;
    //printf("%d %d ",rt,sz);
    m = sz;
    rt = dfs(rt,0);
    //printf("%d\n",rt);
    dfs(rt,0);
    vis[rt] = 1;
    int mx = 0;
    for (int i=head[rt];i;i=nxt[i])
    {
        int v = to[i];
        if (vis[v]) continue ;
        mx = max(mx,solve(v,sum[v]));
    }
    return mx+1;
}
int dp[(1<<20)+12],deg[MAXN];
int find(int u,int f,int all)
{
    int s = (1<<(u-1));
    for (int i=head[u];i;i=nxt[i])
    {
        int v = to[i];
        if (v==f) continue ;
        if ((all&(1<<(v-1)))==0) continue ;
        s |= find(v,u,all);
    }
    return s;
}
int cal(int s)
{
    if (~dp[s]) return dp[s];
    if (s==0) return 0;
    int res = 1e9;
    for (int u=1;u<=n;u++)
    {
        if ((s&(1<<(u-1)))==0) continue ;
        int cur = 0;
        for (int i=head[u];i;i=nxt[i])
        {
            int v = to[i];
            if ((s&(1<<(v-1)))==0) continue ;
            cur = max(cur,cal(find(v,u,s)));
        }
        res = min(res,cur+1);
    }
    return dp[s] = res;
}
void worksmall()
{
    memset(dp,-1,sizeof(dp));
    printf("%d\n",cal((1<<n)-1));
}
bool checkChain()
{
    for (int i=1;i<=n;i++)
        if (deg[i]>2) return 0;
    return 1;
}
void workChain()
{
    int x = n,k = 0;
    while (x)
    {
        x/=2;
        k++;
    }
    printf("%d\n",k);
}
void work()
{
    n = read();
    cnt = 0;
    for (int i=1;i<=n;i++) deg[i] = vis[i] = head[i] = 0;
    for (int i=1;i<n;i++)
    {
        int u = read(),v = read();
        add(u,v),add(v,u);
        deg[u] ++,deg[v] ++;
    }
    if (n<=20)
    {
        worksmall();
        return ;
    }
    if (checkChain())
    {
        workChain();
        return ;
    }
    //cerr << n << endl;
    int ans;
    printf("%d\n",ans = solve(1,n));
    //cerr << ans << endl;
}
int main()
{
    freopen("labyrinth.in","r",stdin);
    freopen("labyrinth.out","w",stdout);
    int t = read();
    while (t--) work();
    return 0;
}