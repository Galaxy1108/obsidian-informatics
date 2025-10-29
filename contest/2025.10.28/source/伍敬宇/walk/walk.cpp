#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 2e5 + 12;
int n,a[MAXN];
long long f[MAXN][5];
int main()
{
    freopen("walk.in","r",stdin);
    freopen("walk.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",a+i);
    memset(f,0x3f3f3f3f,sizeof(f));
    f[0][0] = f[0][1] = f[0][2] = f[0][3] = f[0][4] = 0;
    for (int i=1;i<=n;i++)
    {
        long long mn = 0x3f3f3f3f3f3f3f3f;
        for (int j=0;j<5;j++)
        {
            mn = min(mn,f[i-1][j]);
            long long cst;
            if (j==0||j==4) cst = a[i];
            else if (j==1||j==3) cst = (a[i]&1);
            else if (j==2) cst = ((a[i]&1)^1);
            f[i][j] = mn + cst;
        }
    }
    long long ans = 0x3f3f3f3f3f3f3f3f;
    for (int j=0;j<5;j++)
        ans = min(ans,f[n][j]);
    printf("%lld",ans);
    return 0;
}