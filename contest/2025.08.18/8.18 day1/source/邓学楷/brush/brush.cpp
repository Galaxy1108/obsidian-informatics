#include <cstdio>

int n,m,x;
long long sum;

int main()
{
    freopen("brush.in","r",stdin);
    freopen("brush.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        sum+=x;
    }
    printf("%lld\n",sum);
    return 0;
}