#include <cstdio>
#include <iostream>
using namespace std;
int n,m;
int a[55][55];
int dp[55][55][505],ans;
inline void upd(int&x,int y)
{
    if (x<y) x = y;
}
int main()
{
    freopen("brick.in","r",stdin);
    freopen("brick.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n-i+1;j++)
            scanf("%d",&a[i][j]);
    for (int i=1;i<=n;i++)
    {
        int cur = 0;
        for (int j=0;j<=n-i+1;j++)
        {
            cur += a[j][i];
            for (int t=0;t<=j+1;t++)
                for (int x=j;x<=m;x++)
                {
                    upd(dp[i][j][x],dp[i-1][t][x-j]+cur);
                }
        }
    }
    printf("%d",max(dp[n][0][m],dp[n][1][m]));
    return 0;
}