#include <cstdio>
#define min(x,y) ((x)<(y)?(x):(y))
using ll=long long;

int n;
ll a[200010];

int main()
{
    freopen("easy.in","r",stdin);
    freopen("easy.out","w",stdout);
    int q,op;
    ll x,y,ans;
    scanf("%d%d",&n,&q);
    for (int i=1;i<=n;i++)
        scanf("%lld",a+i);
    while (q--)
    {
        scanf("%d",&op);
        if (op==1)
        {
            scanf("%lld",&x);
            for (int i=1;i<=n;i++)
                a[i]=min(a[i],x);
        }
        else if (op==2)
            for (int i=1;i<=n;i++)
                a[i]+=i;
        else
        {
            scanf("%lld%lld",&x,&y);
            ans=0;
            for (int i=x;i<=y;i++)
                ans+=a[i];
            printf("%lld\n",ans);
        }
    }
    return 0;
}