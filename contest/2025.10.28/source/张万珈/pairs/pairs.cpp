#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 11;
int sum[N*N],mod;
ll ans = 0;
bool vis[N];
int n;
void dfs(int now,int cnt)
{
    if(now > n)
    {
        ans = (ans + sum[cnt+1]) % mod;
        for(int i=cnt;i>=0;i--)
        {
            sum[i]++;
        }
        return;
    }
    cnt += now-1;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            vis[i] = 1;
            dfs(now+1,cnt);
            vis[i] = 0;
        }
        else cnt--;
    }
}
int main()
{
    freopen("pairs.in","r",stdin);
    freopen("pairs.out","w",stdout);
    cin >> n >> mod;
    dfs(1,0);
    cout << ans;
}