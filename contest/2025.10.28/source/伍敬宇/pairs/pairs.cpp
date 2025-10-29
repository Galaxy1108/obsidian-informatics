#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 200 + 12;
const int bas = 200*212/2;
int mod;
int n;
long long f[MAXN][MAXN*MAXN][2];
long long g[MAXN*MAXN];
int main()
{
    freopen("pairs.in","r",stdin);
    freopen("pairs.out","w",stdout);
    scanf("%d%d",&n,&mod);
    f[0][bas][0] = 1;
    int lmt = n*n/2;
    for (int i=1;i<=n;i++)
    {
        // 1 -> 1;
        memset(g,0,sizeof(g));
        long long cur = 0,sum = 0;
        for (int j=-lmt;j<=lmt;j++)
        {
            cur = (cur + f[i-1][j+bas][1] - f[i-1][j+bas-(n-i)-1][1] + mod)%mod;
            g[j+bas] = cur;
        }
        cur = 0;
        for (int j=lmt;j>=-lmt;j--)
        {
            cur = (cur + g[j+bas] - g[j+bas+(n-i)+1] + mod)%mod;
            f[i][j+bas][1] = cur;
        }
        // 0 -> 0
        for (int j=-lmt;j<=lmt;j++)
            f[i][j+bas][0] = 1ll*(n-i+1)*f[i-1][j+bas][0]%mod;
        cur = sum = 0;
        //0 -> 1
        for (int j=-lmt;j<=lmt;j++)
        {
            f[i][j+bas][1] = (sum+f[i][j+bas][1])%mod;
            //printf("%d %d %lld\n",i,j,f[i][j+bas][1]);
            cur = (cur + f[i-1][j+bas][0] - f[i-1][j+bas-(n-i)-1][0] + mod)%mod;
            sum = (sum + f[i-1][j+bas][0]*(n-i+1) - cur + mod)%mod;
        }
    }
    long long ans = 0;
    for (int j=-lmt;j<=-1;j++) ans = (ans + f[n][j+bas][1])%mod;
    printf("%lld",ans);
    return 0;
}