#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;
const int a[10] = {0,0,4225,169,8450,13,4225+169,1,4225*3,169*2};
unsigned long long dp[13][10][160010];
unsigned long long cnt[160010],fac[13];
long long s[1000010],tot;
long long n,k;
bool cmp(long long a,long long b)
{
    return a > b;
}
int main()
{
    freopen("gold.in","r",stdin);
    freopen("gold.out","w",stdout);
    cin >> n >> k;
    for(int i=1;i<=9;i++)
    {
        dp[1][i][a[i]] = 1;
        cnt[a[i]]++;
    }
    long long cnt10=1,n1=n;
    fac[1] = 1;
    while(n1 > 10)
    {
        n1/=10;
        cnt10++;
        fac[cnt10] = fac[cnt10-1] * 10;
    }
    for(int i=2;i<cnt10;i++)
    {
        for(int l=1;l<=9;l++)
        {
            for(int k=0;k<=160000;k++)
            {
                if(!dp[i-1][l][k]) continue;
                for(int j=1;j<=9;j++)
                {
                    dp[i][j][k+a[j]] = (dp[i-1][l][k] + dp[i][j][k+a[j]]) % mod;
                    cnt[k+a[j]] += dp[i-1][l][k];
                }
            }
        }
    }
    for(int l=1;l<=9;l++)
    {
        for(int k=0;k<=160000;k++)
        {
            if(!dp[cnt10-1][l][k]) continue;
            for(int j=1;j<n1;j++)
            {
                dp[cnt10][j][k+a[j]] = (dp[cnt10-1][l][k] + dp[cnt10][j][k+a[j]]) % mod;
                cnt[k+a[j]] += dp[cnt10-1][l][k];
            }
        }
    }
    int lst=a[n1];
    for(int i=cnt10-1;i>=1;i--)
    {
        int now = (n/fac[i]) % 10;
        for(int j=1;j<now;j++)
        {
            for(int k=0;k<=160000;k++)
            {
                if(!dp[i][j][k]) continue;
                cnt[k+lst] += dp[i][j][k];
            }
        }
        if(i==1)
        {
            for(int k=0;k<=160000;k++)
            {
                if(!dp[i][now][k]) continue;
                cnt[k+lst] += dp[i][now][k];
            }
        }
        lst += a[now];
    }
    sort(cnt,cnt+160000+1,cmp);
    unsigned long long ans=0;
    for(int i=0;i<=k;i++)
    {
        if(cnt[i] == 0) break;
        for(int j=0;j<=k;j++)
        {
            if(cnt[j] == 0) break;
            s[++tot] = cnt[i] * cnt[j];
        }
    }
    sort(s+1,s+tot+1,cmp);
    for(int i=1;i<=k;i++)
    {
        ans = (ans+(s[i] % mod)) % mod;
    }
    cout << ans;
    return 0;
}