#include <cstdio>
using namespace std;
const int MAXN = 2e4 + 12;
int pt,n;
__int128 pre;
inline long long mod(long long x)
{
    long long y = (x*pre)>>64;
    return x - y*pt;
}
int p[MAXN],lpf[MAXN],cnt,b[MAXN];
long long rev[MAXN],ans;
long long ton1[MAXN],ton2[MAXN];
void init()
{
    pre = 1;
    pre <<= 64;
    pre = pre/pt;
    b[1] = 1;
    for (int i=2;i<=n;i++)
    {
        if (b[i]==0) p[++cnt] = i,lpf[i] = cnt;
        for (int j=1;j<=cnt&&i*p[j]<=n;j++)
        {
            b[i*p[j]] = 1;
            lpf[i*p[j]] = j;
            if (i%p[j]==0) break;
        }
    }
    rev[1] = 1;
    for (int i=2;i<=n;i++)
        rev[i] = mod(rev[pt%i]*(pt-pt/i));
}
long long pw(long long x,long long k)
{
    long long res = 1;
    while (k)
    {
        if(k&1) res = mod(res*x);
        k>>=1;
        x = mod(x*x);
    }
    return res;
}
int main()
{
    freopen("gonna.in","r",stdin);
    freopen("gonna.out","w",stdout);
    scanf("%d",&n);
    scanf("%d",&pt);
    init();
    for (int x=1;x<=n;x++)
    {
        int t = x;
        while (t>1)
        {
            ton1[lpf[t]] += x-1;
            t /= p[lpf[t]];
        }
        for (int i=1;i<=cnt;i++)
            ton1[i] -= ton2[i];
        long long cur = 1;
        for (int i=1;i<=cnt;i++)
            cur = mod(cur*mod((pw(p[i],ton1[i]+1)-1)*rev[p[i]-1]));
        ans = mod(ans+cur);
        t = x;
        while (t>1)
        {
            ton2[lpf[t]]++;
            t /= p[lpf[t]];
        }
    }
    printf("%lld",ans);
    return 0;
}