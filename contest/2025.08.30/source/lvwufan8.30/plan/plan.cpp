#include<bits/stdc++.h>
using namespace std;
int n,k;
int x,y;
int a[510];
int dp[510][505];
int tot=0;
int head[100001];
int g[510];
int siz[510];
int fa[510];
int dep[510];
struct Edge
{
    int nx,to;
}e[100001];
void edge(int u,int v)
{
    e[++tot].nx=head[u];
    e[tot].to=v;
    head[u]=tot;
}
int gcd(int x,int y)
{
    if(x<y)
    {
        swap(x,y);
    }
    if(y==0)
    {
        return x;
    }
    return gcd(y,x%y);
}
void dfs1(int s,int f,int deep)
{
    fa[s]=f;
    dep[s]=deep;
    for(int i=head[s];i;i=e[i].nx)
    {
        int y=e[i].to;
        if(y==f)
        {
            continue;
        }
        dfs1(y,s,deep+1);
        siz[s]+=siz[y];
    }
}
void DFS(int s)
{
    if(head[s]==0)
    {
        dp[s][0]=a[s];
        return;
    }
    for(int i=head[s];i;i=e[i].nx)
    {
        int y=e[i].to;
        if(y==fa[s])
		{
			continue;
		} 
        DFS(y);
        for(int j=siz[s]-1;j>=0;j--)
        {
            for(int k=0;k<=siz[y]-1;k++)
            {
                if(j-k-1>=0)
                {
                    dp[s][j]=max(dp[s][j],dp[s][j-k-1]+dp[y][k]);
                }
                else
                {
                    break;
                }
            }
        }
    }
}
int main()
{
    freopen("plan.in","r",stdin);
    freopen("plan.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<n;i++)
    {
        cin>>x>>y;
        edge(x,y);
        edge(y,x);
    }
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        siz[i]=1;
        ans+=a[i];
    }
    cout<<ans;
}