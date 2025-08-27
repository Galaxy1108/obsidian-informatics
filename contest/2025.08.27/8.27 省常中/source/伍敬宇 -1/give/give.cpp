#include <cstdio>
#include <bitset>
#include <iostream>
using namespace std;
int n,a[212],mx;
long long m,s;
bitset<200000+12> f[63],temp;
void work()
{
    scanf("%lld%lld%d",&m,&s,&n);
    mx = 0;
    for (int i=1;i<=n;i++) scanf("%d",a+i),mx = max(mx,a[i]);
    for (int i=0;i<=60;i++)
        for (int j=0;j<=mx*2;j++)
            f[i][j] = 0;
    int ans = 0;
    for (int i=0;(1ll<<i)<=m;i++)
    {
        if (i==0)
        {
            if (m&(1ll<<i))
                for (int j=1;j<=n;j++)
                    f[0][a[j]] = 1;
            else 
                f[0][0] = 1;
        }
        else 
        {
            if (m&(1ll<<i))
            {
                for (int k=0;k<=mx*2;k++)
                    temp[k] = 0;
                for (int k=0;k<=mx*2;k++)
                    if (bool(k&1)==bool((s>>(i-1))&1))
                        temp[k/2] = f[i-1][k];
                // for (int j=1;j<=n;j++)
                //     for (int k=0;k<=mx*2;k++)
                //         if (bool(k&1)==bool((s>>(i-1))&1))
                //             f[i][k/2+a[j]] ^= f[i-1][k];
                for (int j=1;j<=n;j++)
                    f[i] ^= (temp<<a[j]);
            }
            else 
            {
                for (int k=0;k<=mx*2;k++)
                    if (bool(k&1)==bool((s>>(i-1))&1))
                        f[i][k/2] = f[i-1][k];
            }
        }
        if ((1ll<<(i+1))>m)
            if ((s>>i)<=mx*2)
                ans = f[i][s>>i];
    }
    printf("%d\n",ans);
}
int main()
{
    freopen("give.in","r",stdin);
    freopen("give.out","w",stdout);
    int t;
    scanf("%d",&t);
    while (t--) work();
    return 0;
}