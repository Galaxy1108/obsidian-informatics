#include <bits/stdc++.h>
using namespace std;
int a[110],b[110],c[110],dp[101][51][51][51];
int main()
{
    freopen("worker.in","r",stdin);
    freopen("worker.out","w",stdout);
    int n;
    cin >> n;
    char cc;
    for(int i=1;i<=n;i++)
    {
        cin >> cc;
        a[i] = a[i-1] + (cc=='A'?1:0);
        b[i] = b[i-1] + (cc=='B'?1:0);
        c[i] = c[i-1] + (cc=='C'?1:0);
    }
    for(int i=0;i<=n;i++)
        for(int j=0;j<=10;j++)
            for(int k=0;k<=10;k++)
                for(int l=0;l<=10;l++)
                    dp[i][j][k][l] = 1000000;
    dp[10][a[10]][b[10]][c[10]] = 0;
    for(int i=10;i<=n;i++)
    {
        for(int j=1;i+j<=n && j<=10;j++)
        {
            int aa = a[i+j] - a[i],bb = b[i+j] - b[i],cc = c[i+j] - c[i];
            if(i+j != n)
            {
                for(int A=0;A<=10;A++)
                for(int B=0;B<=10;B++)
                for(int C=0;C<=10;C++)
                {
                    if(aa+bb+cc+B+C <= 10 && j+B+C <= 10) dp[i+j][aa][B+bb][C+cc] = min(dp[i+j][aa][B+bb][C+cc],dp[i][j][B][C]+1);
                    if(aa+bb+cc+A+C <= 10 && j+A+C <= 10) dp[i+j][A+aa][bb][C+cc] = min(dp[i+j][A+aa][bb][C+cc],dp[i][A][j][C]+1);
                    if(aa+bb+cc+A+B <= 10 && j+A+B <= 10) dp[i+j][A+aa][B+bb][cc] = min(dp[i+j][A+aa][B+bb][cc],dp[i][A][B][j]+1);
                }
            }
            else
            for(int A=0;A<=10;A++)
            for(int B=0;B<=10-A;B++)
            for(int C=0;C<=10-A-B;C++)
            {
                if(aa+bb+cc+B+C <= 10) dp[i+j][aa][B+bb][C+cc] = min(dp[i+j][aa][B+bb][C+cc],dp[i][A][B][C]+1);
                if(aa+bb+cc+A+C <= 10) dp[i+j][A+aa][bb][C+cc] = min(dp[i+j][A+aa][bb][C+cc],dp[i][A][B][C]+1);
                if(aa+bb+cc+A+B <= 10) dp[i+j][A+aa][B+bb][cc] = min(dp[i+j][A+aa][B+bb][cc],dp[i][A][B][C]+1);
            }
        }
    }
    int ans = 100000;
    for(int i=0;i<=10;i++)
    for(int j=0;j<=10;j++)
    for(int k=0;k<=10;k++)
    {
        ans = min(ans,dp[n][i][j][k] + ((i==0)?0:1) + ((j==0)?0:1) + ((k==0)?0:1));
    }
    cout << ans;
    return 0;
}