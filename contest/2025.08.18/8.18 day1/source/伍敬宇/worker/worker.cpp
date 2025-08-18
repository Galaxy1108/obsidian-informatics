#include <cstdio>
#include <cstring>
using namespace std;
int dp[112][12][12][12];
int n;
char s[112];
inline void upd(int&x,int y)
{
    if (y<x) x = y;
}
int main()
{
    freopen("worker.in","r",stdin);
    freopen("worker.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("\n%c",s+i);
    memset(dp,0x3f3f3f3f,sizeof(dp));
    dp[0][0][0][0] = 0;
    for (int i=1;i<=n;i++)
    {
        for (int A=0;A<10;A++)
            for (int B=0;A+B<10;B++)
                for (int C=0;A+B+C<10;C++)
                {
                    int nA = A,nB = B,nC = C;
                    if (s[i]=='A') nA++;
                    else if (s[i]=='B') nB++;
                    else if (s[i]=='C') nC++;
                    upd(dp[i][nA][nB][nC],dp[i-1][A][B][C]);
                    upd(dp[i][0][nB][nC],dp[i-1][A][B][C]+1);
                    upd(dp[i][nA][0][nC],dp[i-1][A][B][C]+1);
                    upd(dp[i][nA][nB][0],dp[i-1][A][B][C]+1);
                    upd(dp[i][nA][0][0],dp[i-1][A][B][C]+2);
                    upd(dp[i][0][nB][0],dp[i-1][A][B][C]+2);
                    upd(dp[i][0][0][nC],dp[i-1][A][B][C]+2);
                    upd(dp[i][0][0][0],dp[i-1][A][B][C]+3);
                }
    }
    printf("%d",dp[n][0][0][0]);
    return 0;
}