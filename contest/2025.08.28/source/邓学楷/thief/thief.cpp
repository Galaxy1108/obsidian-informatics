#include <cstdio>

int n,m,a[500010];
long long ans;

int main()
{
    freopen("thief.in","r",stdin);
    freopen("thief.out","w",stdout);
    int l,r;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        scanf("%d",a+i);
    while (m--)
    {
        scanf("%d%d%lld",&l,&r,&ans);
        for (int i=l;i<=r;i++)
            if (ans<a[i])   ans++;
            else if (ans>a[i])  ans--;
        printf("%lld\n",ans);
    }
    return 0;
}