#include <bits/stdc++.h>
using namespace std;
constexpr int N=505,mod=998244353;
int n,x;
int C[N][N];
int f[N][N];
int qpow(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1)
			res=1ll*res*a%mod;
		a=1ll*a*a%mod;
		b>>=1;		
	}
	return res;
}
void init()
{
	for(int i=0;i<=n;i++)
	{
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
}
int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>x;
	init();
	for(int i=2;i<=n;i++)
		for(int j=1;j<=x;j++)
			if(i>j)
				f[i][j]=(qpow(j,i)-qpow(j-1,i)+mod)%mod;
			else
				for(int k=1;k<=i;k++)
					(f[i][j]+=1ll*C[i][k]*qpow(i-1,i-k)%mod*f[k][j-i+1]%mod)%=mod;
	int ans=0;
	for(int i=1;i<=x;i++)(ans+=f[n][i])%=mod;
	cout<<ans;
	return 0;
}