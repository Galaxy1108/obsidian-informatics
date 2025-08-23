#include <cstdio>
typedef long long ll;

int n,m,p;

int min(int x,int y)
{
    return x<y?x:y;
}

ll qpow(ll x,int y)
{
    ll ans=1;
    x%=p;
    for (;y;y/=2)
    {
        if (y%2)
            ans=(ans*x)%p;
        x=x*x%p;
    }
    return ans%p;
}

int main()
{
    freopen("easyhard.in","r",stdin);
    freopen("easyhard.out","w",stdout);
    scanf("%d%d%d",&n,&m,&p);
    printf("%lld\n",qpow(2,n+m));
    return 0;
}