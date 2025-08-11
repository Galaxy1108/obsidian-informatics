#include <bits/stdc++.h>
using namespace std;
#define f(x,a,b) for(int x = (a);x<=(b);x++)
long dp[15][15][15][15][15][15][15][2];
const int mod = 998244353;
char s[200];
int main()
{
	freopen("abc.in","r",stdin);
	freopen("abc.out","w",stdout);
    int n;
    cin >> n;
    int l = n*3;
    if(n > 15)
    {
        cout << 0;
        return 0;
    }
    cin >> s+1;
    int t=0;
    dp[0][0][0][0][0][0][0][0] = 1;
    for(int i=1;i<=l;i++)
    {
        t^=1;
        if(s[i] == 'A')
        {
            f(abc,0,n)f(a,0,n)f(b,0,min(n,i))f(c,0,n)f(ab,0,n)f(bc,0,n)f(ca,0,n)
            {
                if(!dp[abc][a][b][c][ab][bc][ca][t^1]) continue;
                if(c) dp[abc][a][b][c-1][ab][bc][ca+1][t] = (dp[abc][a][b][c-1][ab][bc][ca+1][t] + dp[abc][a][b][c][ab][bc][ca][t^1]) % mod;
                if(bc) dp[abc+1][a][b][c][ab][bc-1][ca][t] = (dp[abc+1][a][b][c][ab][bc-1][ca][t] + dp[abc][a][b][c][ab][bc][ca][t^1]) % mod;
                dp[abc][a+1][b][c][ab][bc][ca][t] = (dp[abc][a+1][b][c][ab][bc][ca][t] + dp[abc][a][b][c][ab][bc][ca][t^1]) % mod;
            }
        }
        if(s[i] == 'B')
        {
            f(abc,0,n)f(a,0,n)f(b,0,min(n,i))f(c,0,n)f(ab,0,n)f(bc,0,n)f(ca,0,n)
            {
                if(!dp[abc][a][b][c][ab][bc][ca][t^1]) continue;
                if(a) dp[abc][a-1][b][c][ab+1][bc][ca][t] = (dp[abc][a-1][b][c][ab+1][bc][ca][t] + dp[abc][a][b][c][ab][bc][ca][t^1]) % mod;
                if(ca) dp[abc+1][a][b][c][ab][bc][ca-1][t] = (dp[abc+1][a][b][c][ab][bc][ca-1][t] + dp[abc][a][b][c][ab][bc][ca][t^1]) % mod;
                dp[abc][a][b+1][c][ab][bc][ca][t] = (dp[abc][a][b+1][c][ab][bc][ca][t] + dp[abc][a][b][c][ab][bc][ca][t^1]) % mod;
            }
        }
        if(s[i] == 'C')
        {
            f(abc,0,n)f(a,0,n)f(b,0,min(n,i))f(c,0,n)f(ab,0,n)f(bc,0,n)f(ca,0,n)
            {
                if(!dp[abc][a][b][c][ab][bc][ca][t^1]) continue;
                if(b) dp[abc][a][b-1][c][ab][bc+1][ca][t] = (dp[abc][a][b-1][c][ab][bc+1][ca][t] + dp[abc][a][b][c][ab][bc][ca][t^1]) % mod;
                if(ab) dp[abc+1][a][b][c][ab-1][bc][ca][t] = (dp[abc+1][a][b][c][ab-1][bc][ca][t] + dp[abc][a][b][c][ab][bc][ca][t^1]) % mod;
                dp[abc][a][b][c+1][ab][bc][ca][t] = (dp[abc][a][b][c+1][ab][bc][ca][t] + dp[abc][a][b][c][ab][bc][ca][t^1]) % mod;
            }
        }
        if(s[i] == '?')
        {
            f(abc,0,n)f(a,0,n)f(b,0,min(n,i))f(c,0,n)f(ab,0,n)f(bc,0,n)f(ca,0,n)
            {
                if(!dp[abc][a][b][c][ab][bc][ca][t^1]) continue;
                if(c) dp[abc][a][b][c-1][ab][bc][ca+1][t] = (dp[abc][a][b][c-1][ab][bc][ca+1][t] + dp[abc][a][b][c][ab][bc][ca][t^1]) % mod;
                if(bc) dp[abc+1][a][b][c][ab][bc-1][ca][t] = (dp[abc+1][a][b][c][ab][bc-1][ca][t] + dp[abc][a][b][c][ab][bc][ca][t^1]) % mod;
                dp[abc][a+1][b][c][ab][bc][ca][t] = (dp[abc][a+1][b][c][ab][bc][ca][t] + dp[abc][a][b][c][ab][bc][ca][t^1]) % mod;
                if(a) dp[abc][a-1][b][c][ab+1][bc][ca][t] = (dp[abc][a-1][b][c][ab+1][bc][ca][t] + dp[abc][a][b][c][ab][bc][ca][t^1]) % mod;
                if(ca) dp[abc+1][a][b][c][ab][bc][ca-1][t] = (dp[abc+1][a][b][c][ab][bc][ca-1][t] + dp[abc][a][b][c][ab][bc][ca][t^1]) % mod;
                dp[abc][a][b+1][c][ab][bc][ca][t] = (dp[abc][a][b+1][c][ab][bc][ca][t] + dp[abc][a][b][c][ab][bc][ca][t^1]) % mod;
                if(b) dp[abc][a][b-1][c][ab][bc+1][ca][t] = (dp[abc][a][b-1][c][ab][bc+1][ca][t] + dp[abc][a][b][c][ab][bc][ca][t^1]) % mod;
                if(ab) dp[abc+1][a][b][c][ab-1][bc][ca][t] = (dp[abc+1][a][b][c][ab-1][bc][ca][t] + dp[abc][a][b][c][ab][bc][ca][t^1]) % mod;
                dp[abc][a][b][c+1][ab][bc][ca][t] = (dp[abc][a][b][c+1][ab][bc][ca][t] + dp[abc][a][b][c][ab][bc][ca][t^1]) % mod;
            }
        }
    }
    cout << dp[n][0][0][0][0][0][0][t];
    return 0;
}
