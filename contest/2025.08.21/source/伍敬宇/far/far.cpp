#include <cstdio>
#include <iostream>
using namespace std;
const int mod = 998244353;
int n,m;
long long l[46],r[46];
int f[(1<<26)+12],g[(1<<26)+12];
inline bool check(int s)
{
    for (int i=0,j=m-1;i<m;i++,j--)
        if (((s>>i)&1)!=((s>>j)&1))
            return 0;
    return 1;
}
inline long long pw(long long x,int k)
{
    long long res = 1;
    while (k)
    {
        if (k&1) res = res*x%mod;
        x = x*x%mod;
        k>>=1;
    }
    return res;
}
void add(long long s,long long k)
{
    int x = 0;
    for (int i=m-1;i>=0;i--)
    {
        if (s&(1<<i))
        {
            for (int z=0;z<(1<<m);z+=(1<<i))
            {
                int sum = 0;
                for (int y=0;y<(1<<i);y++)
                    sum = (sum + f[z|y])%mod;
                int w = z^x;
                for (int y=0;y<(1<<i);y++)
                    g[w|y] = (g[w|y] + k*sum + mod)%mod;
            }
        }
        x ^= (s&(1<<i));
    }
    for (int t=0;t<(1<<m);t++)
        g[t^s] = (g[t^s] + f[t]*k + mod)%mod;
}
void work1()
{
    f[0] = 1;
    for (int i=1;i<=n;i++)
    {
        if (l[i]) add(l[i]-1,-1);
        add(r[i],1);
        long long ans = 0;
        for (int s=0;s<(1<<m);s++)
        {
            if (check(s))
                ans = (ans + g[s])%mod;
            f[s] = g[s];
            g[s] = 0;
        }
        printf("%lld\n",ans);
    }
}
bool check2()
{
    for (int i=1;i<=n;i++)
    {
        if (l[i]!=0) return 0;
        if (r[i]!=((1ll<<m)-1)) return 0;
    }
    return 1;
}
void work2()
{
    for (int i=1;i<=n;i++)
        printf("%lld\n",pw(2,m*(i-1)+(m+1)/2));
}
long long work3(long long s)
{
    long long res = 0;
    for (int i=m-1;i>=0;i--)
    {
        //printf("%d %d\n",i,i>=m/2||((s&(1ll<<(m-1-i)))==0));
        if ((i>=m/2||((s&(1ll<<(m-1-i)))==0))&&(s&(1ll<<(i))))
        {
        //    printf("%d %d\n",i,min((m+1)/2,i));
            res = (res + pw(2,max(0,(m+1)/2-(m-i))))%mod;
        }
        if (i<m/2&&((s>>i)&1ll)!=((s>>(m-1-i))&1ll)) break;
    }
    if (check(s)) res = (res + 1)%mod;
    return res;
}
int main()
{
    freopen("far.in","r",stdin);
    freopen("far.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        scanf("%lld%lld",l+i,r+i);
    if (n==1)
    {
        long long res = work3(r[1]);
        if (l[1]) res = (res - work3(l[1]-1) + mod)%mod;
        printf("%lld\n",res);
    }
    else if (check2()) work2();
    else work1();
    return 0;
}