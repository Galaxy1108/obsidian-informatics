#include <cstdio>
#include <algorithm>
typedef long long ll;

const int M=1e9+7;
int n,a[5010],cnt[1000010],pre[1000010];
ll prod[1000010]={1},res=1;

ll qpow(ll x,int y)
{
    ll ans=1;
    x%=M;
    for (;y;y/=2)
    {
        if (y%2)
            ans=(ans*x)%M;
        x=x*x%M;
    }
    return ans%M;
}

int main()
{
    freopen("dice.in","r",stdin);
    freopen("dice.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",a+i),cnt[a[i]]++;
    std::sort(a+1,a+n+1);
    for (int i=a[n];i>=1;i--)
        pre[i]=pre[i+1]+cnt[i];
    for (int i=1;i<=a[n];i++)
        prod[i]=prod[i-1]*qpow(i,cnt[i])%M;
    ll rev=qpow(prod[a[n]],M-2);
    for (int i=2;i<=a[n];i++)
        res+=(prod[i-1]*((qpow(i,pre[i])-qpow(i-1,pre[i])+M)%M)%M)*i%M,res%=M;
    printf("%lld\n",res*rev%M);
    return 0;
}