#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,mod;
vector<vector<ll>>f,g;
int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m>>mod;
    f.resize(n+1);
    g.resize(n+1);
    f[1].resize(m+1);
    g[1].resize(m+1);
    for(int j = 1;j <= m;j++) f[1][j] = j,g[1][j] = m-j+1;
    for(int i = 2;i <= n;i++)
    {
        f[i].resize(m+1);
        g[i].resize(m+1);
        for(int j = 1,S = 0;j <= m;j++)
        {
            S = (S + f[i-1][j-1])%mod;
            f[i][j] = (f[i][j-1] + S)%mod;
        }
        for(int j = m,S = 0;j;j--)
        {
            f[i][j] = (f[i][j] + 1ll*S*j)%mod;
            S = (S + g[i-1][j])%mod;
        }
        for(int j = m-1,S = 0;j;j--)
        {
            S = (S + g[i-1][j+1])%mod;
            g[i][j] = (g[i][j+1] + S)%mod;
        }
        for(int j = 1,S = 0;j <= m;j++)
        {
            S = (S + f[i-1][j-1])%mod;
            g[i][j] = (g[i][j] + 1ll*S*(m-j+1))%mod;
        }
        int S = 0;
        for(int j = 1;j <= m;j++) S = (S + f[i-1][j])%mod;
        for(int j = 1;j <= m;j++) f[i][j] = (mod-f[i][j] + 1ll*S*j)%mod,g[i][j] = (mod-g[i][j] + 1ll*S*(m-j+1))%mod;
    }
    int ans = 0;
    for(int j = 1;j <= m;j++) ans = (ans + f[n][j])%mod;
    cout<<ans<<"\n";
    return 0;
}