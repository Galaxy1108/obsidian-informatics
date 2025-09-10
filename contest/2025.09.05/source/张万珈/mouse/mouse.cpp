#include <bits/stdc++.h>
using namespace std;
long double dp[1010][1010];
long double ans;
int main()
{
    freopen("mouse.in","r",stdin);
    freopen("mouse.out","w",stdout);
    int n,m;
    cin >> n >> m;
    dp[n][m] = 1;
    int cnt = 0;
    for(int i=n+m-1;i>=0;i--)
    {
        cnt++;
        for(int w=0;w<=n;w++)
        {
            int b = i-w;
            if(b < 0) break;
            if(cnt%3==1)
            {
                ans += (dp[w+1][b] * (w+1)) / (w+b+1);
                dp[w][b] = (dp[w][b+1] * (b+1)) / (w+b+1);
            }
            else if(cnt%3==2)
            {
                dp[w][b] = (dp[w][b+1] * (b+1)) / (w+b+1);
            }
            else
            {
                dp[w][b] = (dp[w+1][b] * (w+1)) / (w+b+1);
                dp[w][b] += (dp[w][b+1] * (b+1)) / (w+b+1);
            }
        }
        // printf("%.9Lf\n",ans);
    }
    
    printf("%.9Lf",ans);
}