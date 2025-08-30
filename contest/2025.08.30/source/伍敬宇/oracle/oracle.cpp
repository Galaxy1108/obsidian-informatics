#include <cstdio>
using namespace std;
int n,m;
int l[33],r[33],k;
int vis[33];
int ans;
int s[22];
int check()
{
    for (int x=1;x<=n;x++)
    {
        s[x] = 0;
        for (int i=1;i<=k;i++)
            if (vis[i]&&l[i]<=x&&x<=r[i])
                s[x] |= (1<<(i-1));
    }
    for (int x=1;x<=n;x++)
        for (int y=x+1;y<=n;y++)
            if (s[x]==s[y])
                return 0;
    return 1;
}
void dfs(int id,int sum)
{
    if (sum>m||sum+k-id+1<m) return ;
    if (id>k)
    {
        ans += check();
        return ;
    }
    dfs(id+1,sum);
    vis[id] = 1;
    dfs(id+1,sum+1);
    vis[id] = 0;
}
int main()
{
    freopen("oracle.in","r",stdin);
    freopen("oracle.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        for (int j=i;j<=n;j++)
        {
            k++;
            l[k] = i,r[k] = j;
        }
    dfs(1,0);
    printf("%d",ans);
    return 0;
}