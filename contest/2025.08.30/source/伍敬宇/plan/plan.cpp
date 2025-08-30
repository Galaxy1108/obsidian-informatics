#include <cstdio>
#include <cmath>
#include <cstring>
#include <map>
using namespace std;
const int MAXN = 200 + 12;
const int A = 1e5;
int n,k,a[MAXN];
int head[MAXN],to[MAXN<<1],nxt[MAXN<<1],cnt,sum[MAXN];
map<int,int> f[MAXN][MAXN];
int res[MAXN][1000+12];
int gu[MAXN],gv[MAXN],tp[MAXN];
inline void upd(int&x,int y)
{
    if (y>x) x = y;
}
inline void add(const int&u,const int&v)
{
    cnt++;
    to[cnt] = v;
    nxt[cnt] = head[u];
    head[u] = cnt;
}
void dfs(int u,int fa)
{
    sum[u] = 1;
    f[u][1][a[u]] = 0;
    for (int i=head[u];i;i=nxt[i])
    {
        int v = to[i];
        if (v==fa) continue ;
        dfs(v,u);
        for (int i=0;i<=sum[u]+sum[v];i++)
            for (int j=0;j<=a[u];j++)
                res[i][j] = 0xc0c0c0c0;
        for (int i=0;i<=sum[v];i++)
            tp[i] = 0xc0c0c0c0;
        for (int i=0;i<=sum[v];i++)
            for (int y=1;y<=a[v];y++)
                if (f[v][i].count(y))
                    upd(tp[i],f[v][i][y]+y);
        for (int x=1;x<=a[u];x++)
        {
            if (a[u]%x!=0) continue ;
            for (int k1=1;k1<=sum[u];k1++)
            {
                gu[k1] = 0xc0c0c0c0;
                for (int y=x;y<=a[u];y+=x)
                    if(f[u][k1].count(y)) upd(gu[k1],f[u][k1][y]);
            }
            for (int k2=1;k2<=sum[v];k2++)
            {
                gv[k2] = 0xc0c0c0c0;
                for (int y=x;y<=a[v];y+=x)
                    if(f[v][k2].count(y)) upd(gv[k2],f[v][k2][y]); 
            }
            for (int k1=1;k1<=sum[u];k1++)
                for (int k2=1;k2<=sum[v];k2++)
                {
                    upd(res[k1+k2-1][x],gu[k1]+gv[k2]);
                    if (f[u][k1].count(x)&&tp[k2]>=0)
                        upd(res[k1+k2][x],f[u][k1][x]+tp[k2]);
                }
        }
        sum[u] += sum[v];
        for (int i=1;i<=sum[u];i++)
            for (int x=1;x<=a[u];x++)
            {
                if (res[i][x]>=0)
                    f[u][i][x] = res[i][x];//,printf("u %d i %d x %d   %d\n",u,i,x,res[i][x])
                else if (f[u][i].count(x))
                    f[u][i][x] = 0xc0c0c0c0;
            }
                
    }
}
inline int gcd(int a,int b)
{
    int r;
    while (b)
    {
        r = a%b;
        a = b,b = r;
    }
    return a;
}
int dp[MAXN][MAXN];
void work()
{
    memset(dp,0xc0c0c0c0,sizeof(dp));
    dp[0][0] = 0;
    for (int i=1;i<=n;i++)
    {
        int x = a[i];
        for (int j=i;j>=1;j--)
        {
            x = gcd(x,a[j]);
            for (int k=1;k<=n;k++)
                upd(dp[i][k],dp[j-1][k-1] + x);
        }
    }
    printf("%d",dp[n][k+1]);
}
int main()
{
    freopen("plan.in","r",stdin);
    freopen("plan.out","w",stdout);
    scanf("%d%d",&n,&k);
    int flag = 1;
    for (int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        if ((u!=i||v!=i+1)&&(v!=i||u!=i+1)) flag = 0;
        add(u,v),add(v,u);
    }
    for (int i=1;i<=n;i++) scanf("%d",a+i);
    if (flag) work();
    else 
    {
        dfs(1,0);
        int ans = 0;
        for (map<int,int>::iterator it=f[1][k+1].begin();it!=f[1][k+1].end();it++)
            upd(ans,(it->first)+(it->second));
        printf("%d",ans);
    }
    
    return 0;
}