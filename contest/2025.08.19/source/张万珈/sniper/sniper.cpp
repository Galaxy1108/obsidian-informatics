#include <bits/stdc++.h>
using namespace std;
long int vis[25010],mp[25010][21],dp[25010][21];
const int v[30] = {0,100,100,97,96,95,90,85,80,82,78,75,70,65,55,50,15,12,10,8,5,2};
int main()
{
    freopen("sniper.in","r",stdin);
    freopen("sniper.out","w",stdout);
    int n;
    cin >> n;
    int t;
    for(int i=1,u,v;i<=n;i++)
    {
        cin >> v >> u >> t;
        if(v==15)
        {
            vis[t] = u;
        }
        mp[t][u] = v;
    }
    for(int i=1;i<=t;i++)
    {
        if(vis[i])
        {
            for(int k=-2;k<=2;k++)
            {
                if(vis[i] + k < 1 || vis[i] + k > 20) continue;
                dp[i+2][vis[i]] = max(dp[i+2][vis[i]],dp[i][vis[i]+k] + v[15]);
            }
            continue;
        }
        else
        {
            for(int u=1;u<=20;u++)
            {
                for(int k=-2;k<=2;k++)
                {
                    if(u+k < 1 || u+k > 20) continue;
                    dp[i+1][u+k] = max(dp[i+1][u+k],dp[i][u]);
                    if(mp[i][u+k])
                    {
                        dp[i+2][u+k] = max(dp[i+2][u+k],dp[i][u] + v[mp[i][u+k]]);
                    }
                }
            }
        }
    }
    long int ans = 0;
    for(int i=1;i<=20;i++)
    {
        ans = max(ans,max(dp[t+1][i],dp[t+2][i]));
    }
    cout << ans;
}