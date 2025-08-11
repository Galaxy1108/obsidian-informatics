#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=5005,mod=998244353;
int n,m;
int s[N];
int f[N][N];
int sum;
int ans;
int qpow(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1)
			res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
signed main()
{
	freopen("mex.in","r",stdin);
	freopen("mex.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>s[i],sum+=!s[i];
	if(n<=m)
		return cout<<qpow(m,sum),0;
	else
	{
		f[0][0]=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m+1;j++)
				if(s[i]==1)
					f[i][j]=f[i-1][j-1];
				else
					f[i][j]=(f[i-1][j]*j%mod+f[i-1][j-1]*(m-j+1)%mod)%mod;
		for(int i=1;i<=m+1;i++)
			ans=(ans+f[n][i])%mod;
		cout<<ans;
	}
	return 0;
}
