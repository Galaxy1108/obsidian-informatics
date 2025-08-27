#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long ll;

int n,a[100010];
short dp[2010][5010];
ll m,s;

int main()
{
    freopen("give.in","r",stdin);
    freopen("give.out","w",stdout);
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%lld%lld%d",&m,&s,&n);
        for (int i=1;i<=n;i++)
            scanf("%d",a+i),dp[1][a[i]]=1;
        std::sort(a+1,a+n+1);
        for (int i=2;i<=m;i++)
        {
            for (int j=1;j<=n;j++)
                for (int k=a[j];k<=s;k++)
                        dp[i][k]+=dp[i-1][k-a[j]],dp[i][k]%=2;
        }
        printf("%hd\n",dp[m][s]%2);
        memset(dp,0,sizeof dp);
    }
    return 0;
}