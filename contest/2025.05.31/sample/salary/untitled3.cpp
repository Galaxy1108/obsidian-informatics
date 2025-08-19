#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD=998244353;
const int N=205;
long long mpow(long long a, long long b) {
	a %= MOD;
	long long res = 1;
	while (b > 0) {
		if (b & 1) res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}
ll d(int n,ll a[][N])
{
	char sign=0;
	ll ans = 1ll;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			int x=i,y=j;
			while(a[y][i])
			{
				ll t=a[x][i]/a[y][i];
				for(int k=1;k<=n;k++)
				{
					a[x][k]=(a[x][k]-a[y][k]*t)%MOD;
				}
				swap(x,y);
			}
			if(x!=i)
			{
				for(int k=1;k<=n;k++)
				{
					swap(a[i][k],a[x][k]);
				}
				sign ^=1;
			}
		}
		ans=ans*a[i][i]%MOD;
	}
	if(sign) ans = - ans;
	if(ans<0) ans+=MOD;
	return ans;
}
ll G[N][N][30],A[N][N];
int n,m;
int main()
{
	freopen("salary2.in","r",stdin);
	cin>>n>>m;
	for(int u,v,w,i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		for(int i=0;(1l << i)<=w;i++)
		{
			if(w&(1l<<i)) G[u][v][i]=++G[v][u][i];
		}
		A[u][v]=--A[v][u];
		++A[u][u];
		++A[v][v];
	}
	ll inv=mpow(d(n-1,A),MOD-2),ans=0;
	for(int k=0;(1l<<k)<=1e9;k++)
	{
		memset(A,0,sizeof(A));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(G[i][j][k]) A[i][j]=-G[i][j][k],A[i][i]+=G[i][j][k];
			}
		}
		ans=(ans+(1ll<<k)*d(n-1,A)%MOD*inv%MOD)%MOD;
	}
	cout<<ans;
	return 0;
}
