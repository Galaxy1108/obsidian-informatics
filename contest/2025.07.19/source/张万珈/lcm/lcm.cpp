#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n,k;
long long ans=1;
void dfs(int x,long long nowlcm)
{
    if(x > k)
    {
        ans = (ans * nowlcm) % mod;
        return;
    }
    for(long long i=1;i<=n;i++)
    {
        dfs(x+1,nowlcm/__gcd(nowlcm,i)*i);
    }
}
int main()
{
	freopen("lcm.in","r",stdin);
	freopen("lcm.out","w",stdout);
    int T;
    cin >> T;
    while(T--)
    {
    cin >> n >> k;
    dfs(1,1);
    cout << ans << '\n';
    ans = 1;
    }
    return 0;
}
