#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
const int SIZE = 1<<21;
const int MAXN = 2000 + 12;
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
int n,m;
struct Edge{
    int u,v,w;
    bool operator<(const Edge&rhs) const{
        return w<rhs.w;
    }
}E[MAXN*MAXN/2];
long long dp[MAXN];
int d[MAXN][MAXN],flag[MAXN];
long long bs;
int main()
{
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    n = read();
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
        {
            m++;
            E[m].u = i,E[m].v = j;
            d[i][j] = d[j][i] = E[m].w = read();
        }
    sort(E+1,E+m+1);
    bs = 1ll*E[1].w*(n-1);
    for (int i=m;i>=1;i--)
        E[i].w -= E[1].w;
    for (int i=1;i<=m;i++)
    {
        int u = E[i].u,v = E[i].v,w = E[i].w;
        if (w==0)
        {
            flag[u] = flag[v] = 1;
        }
    }
    for (int i=1;i<=n;i++)
    {
        dp[i] = 1e17;
        for (int j=1;j<=n;j++)
            if (flag[j])
                dp[i] = min(dp[i],1ll*d[i][j]);
    }
    for (int i=1;i<=m;i++)
    {
        int u = E[i].u,v = E[i].v,w = E[i].w;
        //printf("%d %d %d\n",u,v,w);
        dp[u] = min(dp[u],dp[v]+w);
        dp[v] = min(dp[v],dp[u]+w);
        dp[u] = min(dp[u],w*2ll);
        dp[v] = min(dp[v],w*2ll);
        //for (int i=1;i<=n;i++) printf("%lld ",dp[i]);
        //printf("\n");
    }
    for (int i=1;i<=n;i++)
        printf("%lld\n",dp[i]+bs);
    return 0;
}