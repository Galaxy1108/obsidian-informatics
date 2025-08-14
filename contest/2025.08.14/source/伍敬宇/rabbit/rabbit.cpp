#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 100 + 12;
const int MAXM = 10000 + 12;
const int mod = 998244353;
int n,m,s,t;
int U[MAXM],V[MAXM],W[MAXM];
int deg[MAXN];
long long a[MAXN][MAXN];
long long p[MAXN],E1[MAXN],E2[MAXN];
long long pw(long long x,int k)
{
	long long res = 1;
	while (k)
	{
		if (k&1) res = res*x%mod;
		k>>=1;
		x = x*x%mod;
	}
	return res;
}
long long rev(long long x)
{
	return pw(x,mod-2);
}
void gause(long long*tar)
{
	for (int c=1;c<=n;c++)
	{
		int mx = c;
		for (int r=c+1;r<=n;r++)
			if (a[r][c]>a[mx][c]) mx = r;
		swap(a[mx],a[c]);
		long long k = rev(a[c][c]);
		for (int i=c;i<=n+1;i++) a[c][i] = a[c][i]*k%mod;
		for (int r=1;r<=n;r++)
		{
			if (r==c) continue ;
			long long q = a[r][c];
			for (int i=c;i<=n+1;i++)
				a[r][i] = (a[r][i]-a[c][i]*q%mod+mod)%mod;
		}
	}
	for (int i=1;i<=n;i++)
		tar[i] = a[i][n+1];
}
int main()
{
	freopen("rabbit.in","r",stdin);
	freopen("rabbit.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d",U+i,V+i,W+i);
		deg[U[i]] ++;
	}
	for (int i=1;i<=n;i++) a[i][i] = mod-1;
	for (int i=1;i<=m;i++)
	{
		if(U[i]!=t) a[V[i]][U[i]] = (a[V[i]][U[i]] + rev(deg[U[i]]))%mod;
	}
	a[s][n+1] = (a[s][n+1]-1+mod)%mod;
	gause(p);
//	for (int i=1;i<=n;i++)
//		printf("%lld ",p[i]);
	memset(a,0,sizeof(a));
	for (int i=1;i<=n;i++) a[i][i] = mod-1;
	for (int i=1;i<=m;i++)
	{
		if (U[i]!=t&&W[i]==1) a[V[i]][U[i]] = (a[V[i]][U[i]] + rev(deg[U[i]]))%mod,
			a[V[i]][n+1] = (a[V[i]][n+1]-rev(deg[U[i]])*p[U[i]]%mod+mod)%mod;
	}
	gause(E1);
	memset(a,0,sizeof(a));
//	for (int i=1;i<=n;i++)
//		printf("%lld ",E1[i]);
	printf("%lld ",E1[t]);
	for (int i=1;i<=n;i++) a[i][i] = mod-1;
	for (int i=1;i<=m;i++)
	{
		if (U[i]!=t&&W[i]==1) a[V[i]][U[i]] = (a[V[i]][U[i]] + rev(deg[U[i]]))%mod,
			a[V[i]][n+1] = (a[V[i]][n+1]-rev(deg[U[i]])*(p[U[i]]+2ll*E1[U[i]]%mod)%mod+mod)%mod;
	}
	gause(E2);
//	for (int i=1;i<=n;i++)
//		printf("%lld ",E2[i]);
	printf("%lld",(E2[t]-E1[t]*E1[t]%mod+mod)%mod);
	return 0;
}
