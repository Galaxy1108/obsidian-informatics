#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=1005;
int n,x,mod,m;
int a[N];
int C[N][N];
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
	freopen("combination.in","r",stdin);
	freopen("combination.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>x>>mod>>m;
	for(int i=0;i<=m;i++)
		cin>>a[i];
	if(!m)
	{
		cout<<a[0]*qpow(x+1,n)%mod;
		return 0;
	}
	C[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=i;j++)
			C[i][j]=(((j)?C[i-1][j-1]:0)+C[i-1][j])%mod;
	for(int k=0,xk=1;k<=n;xk=xk*x%mod,k++)
	{
		int sum=0,ki=1;
		for(int i=0;i<=m;ki*=k,i++)
			sum=(sum+a[i]*ki%mod)%mod;
		ans=(ans+xk*C[n][k]%mod*sum%mod)%mod;
	}
	cout<<ans;
	return 0;
}
