#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
int n,m;
int a[100005];
int f[2005][2005];
long long fpow(long long a, long long b) {
	a %= MOD;
	long long res = 1;
	while (b > 0) {
		if (b & 1) res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}
int main()
{
	freopen("messenger.in","r",stdin);
	freopen("messenger.out","w",stdout);
	memset(f,0x3f,sizeof(f));
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		f[u][v]=fpow(2,i);
		f[v][u]=fpow(2,i);
	}
	for(int k=1;k<=n;k++)
	{
		for(int x=1;x<=n;x++)
		{
			for(int y=1;y<=n;y++)
			{
				f[x][y]=min(f[x][y],f[x][k]+f[k][y]);
			}
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++)//信箱
	{
		for(int j=1;j<=n;j++)//邮局
		{
			if(a[i]==1)
			{
				break;
			}
			if(a[j]==0)
			{
				continue;
			}
			ans+=f[j][i];
//			cout<<j<<" "<<i<<" "<<f[j][i]<<endl;
		}
	}
	cout<<ans%MOD;
	return 0;
}
