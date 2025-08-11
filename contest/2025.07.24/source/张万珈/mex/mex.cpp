#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int dp[5010][5010][2];
long long n,m,cnt0,cnt1;
bool vis[5010];
inline long long qpow(long long a,long long b)
{
	long long ret=1;
	while(b)
	{
		if(b&1)
			ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;		
	}
	return ret;
}
int main()
{
	freopen("mex.in","r",stdin);
	freopen("mex.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> vis[i];
        if(vis[i]) cnt1++;
        else cnt0++;
    }
    dp[0][0][0] = 1;
    int t=0;
    long long ans = 1;
    for(long long i=1;i<=cnt0;i++)
    {
        ans = ans*m%mod;
    }
    cout << ans ;
}
