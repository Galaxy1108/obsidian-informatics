#include <cstdio>
#include <algorithm>

int n,h[100],a[100],f[100],s[210],cnt[210];
long long tot;

int abs(int x)
{
    return x>=0?x:-x;
}

int main()
{
    freopen("lineup.in","r",stdin);
    freopen("lineup.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",h+i),a[i]=h[i];
    std::sort(a+1,a+n+1);
    for (int i=1;i<=n;i++)
    {
        if (!s[a[i]])
            s[a[i]]=i;
    }
    for (int i=1;i<=n;i++)
    {
        f[i]=s[h[i]]+cnt[h[i]];
        cnt[h[i]]++;
    }
    for (int i=1;i<=n;i++)
        tot+=abs(f[i]-i);
    printf("%lld\n",tot);
    return 0;
}