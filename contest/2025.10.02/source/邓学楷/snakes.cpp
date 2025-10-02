#include <cstdio>

int T,n,a[10],k,x,y;

int solve()
{
    if (a[3]-a[1]>=a[2])
        return 1;
    else
        return 3;
}

int main()
{
    freopen("snakes.in","r",stdin);
    freopen("snakes.out","w",stdout);
    scanf("%d%d",&T,&n);
    T--;
    for (int i=1;i<=n;i++)
        scanf("%d",a+i);
    printf("%d\n",solve());
    while (T--)
    {
        scanf("%d",&k);
        while (k--)
            scanf("%d%d",&x,&y),a[x]=y;
        printf("%d\n",solve());
    }
    return 0;
}