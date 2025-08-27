#include <bits/stdc++.h>
using namespace std;

int m,s,n;
int a[210];
bool dp[2010][5010];

void solve()
{
    cin >> m >> s >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    int mn=0;
    for(int k=0;k<m;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=mn;j<=s-a[i];j++)
            {
                if(!dp[k][j]) continue;
                dp[k+1][j+a[i]] = dp[k][j] ^ dp[k+1][j+a[i]];
            }
        }
        mn += a[1];
    }
    cout << (dp[m][s]?1:0) << endl;
}
void init()
{
    for(int i=1;i<=m;i++)
        for(int j=0;j<=s;j++)
            dp[i][j] = 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    freopen("give.in","r",stdin);
    freopen("give.out","w",stdout);
    int T;
    cin >> T;
    dp[0][0] = 1;
    while(T--)
    {
        solve();
        init();
    }
}