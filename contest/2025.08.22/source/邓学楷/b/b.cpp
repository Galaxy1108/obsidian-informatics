#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int n,minn[2010];
long long ans;
struct edge
{
    int to,dis;
};
vector<edge> vec[2010];
bool vis[2010];

int min(int x,int y)
{
    return x<y?x:y;
}

void dfs(int u,int cnt,int dis)
{
    if (cnt==n+1)
        return;
    minn[u]=min(minn[u],dis);
    for (edge v:vec[u])
        if (!vis[v.to])
        {
            vis[v.to]=1;
            dfs(v.to,cnt+1,min(dis,v.dis));
            vis[v.to]=0;
        }
}

int main()
{
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    int x;
    scanf("%d",&n);
    for (int i=1;i<n;i++)
        for (int j=1;j<=n-i;j++)
        {
            scanf("%d",&x);
            vec[i].push_back(edge{i+j,x});
            vec[i+j].push_back(edge{i,x});
        }
    for (int i=1;i<=n;i++)
    {
        memset(vis,0,sizeof vis);
        memset(minn,0x7f,sizeof minn);
        vis[i]=1,ans=0,minn[i]=0;
        dfs(i,0,0x7f7f7f7f);
        for (int i=1;i<=n;i++)
            ans+=minn[i];
        printf("%lld\n",ans);
    }
    return 0;
}