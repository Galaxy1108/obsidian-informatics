#include <bits/stdc++.h>
// #pragma GCC optimize(2)
using namespace std;
constexpr int N=3005;
bool m1;
int n,m,mod;
int f[N][4][N];
int g[N][4];
int ans;
bool m2;
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
int main()
{
	freopen("easyhard.in","r",stdin);
	freopen("easyhard.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>mod;
	for(int i=0;i<=n;i++)
		f[0][0][i]=1;
	g[0][0]=1;
	for(int i=1;i<=m;i++)
	{
		for(int k=0;k<4;k++)
		{
			if(k==0 || k==1)
				for(int kk=0;kk<4;kk++)
				{
					int res=0;
					for(int j=1;j<=n;j++)
						res|=f[i-1][kk][j];
					if(res)
					{
						g[i][k]=(g[i][k]+g[i-1][kk])%mod;
						for(int j=1;j<=n;j++)
							f[i][k][j-(k==0?0:1)]|=f[i-1][kk][j];
					}
				}
			else
			{
				for(int kk=0;kk<4;kk++)
				{
					int res=0;
					for(int j=0;j<n;j++)
						res|=f[i-1][kk][j];
					if(res)
					{
						g[i][k]=(g[i][k]+g[i-1][kk])%mod;
						for(int j=0;j<n;j++)
							f[i][k][j+(k==2?0:1)]|=f[i-1][kk][j];
					}
				}
			}
		}
		// int sum=0;
		// for(int j=0;j<4;j++)
		// {
		// 	cout<<g[i][j]<<' ';
		// 	sum=(sum+g[i][j])%mod;
		// }
		// cout<<sum<<'\n';
	}
	for(int i=0;i<4;i++)
		ans=(ans+g[m][i])%mod;
	cout<<ans;
	// cerr<<fabs(&m1-&m2)/1024.0/1024.0<<"MB\n"<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
	return 0;
}