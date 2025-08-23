#include <bits/stdc++.h>
using namespace std;
#define il inline
#define ll long long
const int N=1e6+5;
int n,fa[N],W[N],rt;
struct edge {
    int v,nxt,w;
}e[N<<1];
int head[N],et=0;
il void add(int u,int v,int w)
{
    e[++et].v=v;
    e[et].nxt=head[u],e[et].w=w;
    head[u]=et;
}
ll a[5005][5005],c[5005][5005],val[N],siz[N],maxn[N];
il void dfs1(int u,int s,int fa)
{
    siz[u]=1;
    for(int i=head[u];i;i=e[i].nxt)
    {
        int v=e[i].v;
        if(v==fa)continue;
        dfs1(v,s,u);
        siz[u]+=siz[v];
        c[s][e[i].w]+=siz[v];
    }
}
il void solve1()
{
    for(int i=1;i<=n;i++){
        dfs1(i,i,0);
    }
    for(int i=1;i<n;i++)for(int j=1;j<=n;j++)a[j][i]=1ll*W[i]*c[j][i];
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<n;j++)cout<<a[i][j]<<' ';
    //     cout<<'\n';
    // }
    for(int i=1;i<=n;i++)
    {
        ll mx=0;
        for(int j=1;j<n;j++)mx=max(mx,a[i][j]);
        for(int j=1;j<n;j++)if(a[i][j]==mx)val[j]++;
    }
    ll ans=0;
    // for(int i=1;i<n;i++)cout<<val[i]<<' ';
    // cout<<'\n';
    for(int i=1;i<n;i++)ans^=val[i];
    cout<<ans<<' ';
}
il void dfs2(int u,int fa)
{
    siz[u]=1;int mx1=0;
    for(int i=head[u];i;i=e[i].nxt)
    {
        int v=e[i].v;
        if(v==fa)continue;
        dfs2(v,u);
        maxn[u]=max(maxn[u],siz[v]);
        siz[u]+=siz[v];
        if(maxn[v]<=n-siz[v])val[e[i].w]++;
        if(mx1<siz[v])mx1=siz[v];
    }
    for(int i=head[u];i;i=e[i].nxt)
    {
        int v=e[i].v;
        if(v==fa)continue;
        if(siz[v]>=n-siz[u]&&siz[v]==mx1)val[e[i].w]++;
    }
}
il void solve2()
{
    dfs2(rt,0);int ans=0;
    // for( int i=1;i<n;i++)cout<<val[i]<<' ';
    // cout<<'\n';
    for(int i=1;i<n;i++)ans^=val[i];
    cout<<ans<<' ';
}
int in[N];
int main()
{
    freopen("treeq.in","r",stdin);
    freopen("treeq.out","w",stdout);
    cin>>n;int flag=0,fl=0;
    for(int i=2,faa,w;i<=n;i++){cin>>faa>>w;add(i,faa,i-1),add(faa,i,i-1);fa[i-1]=faa,W[i-1]=w,in[i]++,in[faa]++;if(faa!=1)flag=1;if(w!=1)fl=1;}
    for(int i=1;i<=n;i++)if(1==in[i]){rt=i;break;}
    if(!flag)cout<<((n&1)^2);
    else if(!fl)solve2();
    else 
        solve1();
    return 0;
}
/*
5
1 3
2 1
3 1
3 1

5
1 1
2 1
3 1
3 1

9
1 1
1 1 
3 1
3 1
3 1
2 1
2 1
2 1

*/