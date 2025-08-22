#include <cstdio>

int n,m,p,ans;

void dfs(int cur,int ll,int lr)
{
    if (cur==n+1)
    {
        ans++;
        ans%=p;
        return;
    }
    for (int l=1;l<=lr;l++)
        for (int r=(l>ll?l:ll);r<=m;r++)
            dfs(cur+1,l,r);
}

int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    scanf("%d%d%d",&n,&m,&p);
    if (n==1)
        printf("%lld\n",1ll*m*(m+1)/2%p);
    else if (m==1)
        puts("1");
    else
    {
        dfs(1,0,m);
        printf("%d\n",ans);
    }
    return 0;
}