#include <cstdio>
using namespace std;
const int MAXN = 1e7 + 12;
const int mod = 998244353;
int n,w,p[MAXN],b[MAXN],cnt;
int lpf[MAXN],tm[MAXN],pw[MAXN],sum[MAXN],qul[MAXN];
int sta[MAXN];
int rev[MAXN];
long long ans;
inline long long qpw(long long x,int k)
{
    long long res = 1;
    while (k)
    {
        if (k&1) res = res*x%mod;
        k>>=1;
        x = x*x%mod;
    }
    return res;
}
void init()
{
    b[1] = 1;
    for (int i=2;i<=n;i++)
    {
        if (b[i]==0) p[++cnt] = i,lpf[i] = pw[i] = i,sum[i] = tm[i] = 1;
        for (int j=1;p[j]*i<=n&&j<=cnt;j++)
        {
            int id = i*p[j];
            b[id] = 1;
            lpf[id] = p[j];
            if (i%p[j]==0)
            {
                tm[id] = tm[i] + 1;
                sum[id] = sum[i];
                pw[id] = pw[i]*p[j];
                break;
            }
            else 
            {
                tm[id] = 1;
                sum[id] = sum[i] + 1;
                pw[id] = p[j];
            }
        }
    }
    rev[1] = 1;
    for (int i=2;i<=n;i++)
        rev[i] = 1ll*rev[mod%i]*(mod-mod/i)%mod;
}
int main()
{
    freopen("gcd.in","r",stdin);
    freopen("gcd.out","w",stdout);
    scanf("%d",&n);
    init();
    for (int i=1;i<=cnt;i++)
        sta[p[i]] = 1;
    scanf("%d",&w);
    for (int i=1;i<=w;i++)
    {
        int x,a;
        scanf("%d%d",&x,&a);
        sta[x] = a + 1;
    }
    qul[1] = 1;
    for (int i=2;i<=n;i++)
        if (tm[i]==sta[lpf[i]]) qul[i] = qul[i/pw[i]];
    //printf("%d\n",rev[4]);
    int cnt0 = qpw(2,cnt-1) - 1,cnt1 = qpw(2,cnt-1);
    for (int i=2;i<=n;i++)
    {
        if (qul[i]==0) continue ;
        long long E = 1ll*n*rev[n - n/i]%mod;
        //printf("%lld %d\n",E,rev[n-n/i]);
        if (sum[i]%2==1)
        {
            ans += E;
            //if (ans >= mod) ans -= mod;
            cnt1 --;
        }
        else 
        {
            ans -= E;
            //if (ans < 0) ans += mod;
            cnt0 --;
        }
    }
    ans += cnt1 - cnt0;
    ans = (ans%mod + mod)%mod;
    printf("%lld\n",ans);
    return 0;
}