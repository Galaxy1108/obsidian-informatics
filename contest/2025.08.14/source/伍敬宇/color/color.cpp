#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int mod = 998244353;
int sta[2512][12],len[2512],idx;
int n,x[112],s,t;
int cur[12],bg[12],temp[12];
long long al,C[112][112],rfct[112],fct[112];
long long a[112][112],ans[112];
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
void gen(int id,int cnt)
{
	if (cnt==n)
	{
		len[++idx] = id-1;
		for (int i=1;i<id;i++)
			sta[idx][i] = cur[i];
		int flag = 1;
		for (int i=1;i<id;i++)
			if (bg[i]!=cur[i])
				flag = 0;
		if (flag) s = idx;
		if (id==2) t = idx;
		return ;
	}
	for (int x=max(1,cur[id-1]);x+cnt<=n;x++)
	{
		cur[id] = x;
		gen(id+1,cnt+x);
	}
}
bool cmp(int x,int y)
{
	if (x==0) return 0;
	if (y==0) return 1;
	return x<y;
}
void add(int u,int v,long long p)
{
	if (u==t) return ;
	a[v][u] = (a[v][u] + p)%mod;
}
void dfs2(int id,int k,long long p,int u)
{
	// ¼õÖ¬ 
	if (id>n)
	{
		if (k!=0) return ;
		for (int i=1;i<=n;i++) temp[i] = cur[i];
		sort(temp+1,temp+n+1,cmp);
		for (int i=1;i<=idx;i++)
		{
			int flag = 1;
			for (int j=1;j<=n;j++)
				if (sta[i][j]!=temp[j]) flag = 0;
			if (flag)
			{
				add(u,i,p);
				return ;
			 } 
		}
		return ;
	}
	dfs2(id+1,k,p,u);
	if (k>0) 
	{
		cur[id] ++;
		dfs2(id+1,k-1,p,u);
		cur[id] --;
	}
}
void dfs1(int id,int k,long long p,int u)
{
	if (id>n)
	{
		dfs2(1,k,p*rev(C[n][k])%mod,u);
		return ;
	}
	for (int x=0;x<=cur[id];x++)
	{
		cur[id] -= x;
		dfs1(id+1,k+x,p*C[cur[id]+x][x]%mod,u);
		cur[id] += x;
	}
}
void gause(long long*tar)
{
	int n = idx;
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
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	for (int i=0;i<100;i++)
	{
		C[i][0] = C[i][i] = 1;
		for (int j=1;j<i;j++)
			C[i][j] = (C[i-1][j-1] + C[i-1][j])%mod;
	}
	fct[0] = rfct[0] = 1;
	for (int i=1;i<100;i++)
		fct[i] = fct[i-1]*i%mod,
		rfct[i] = rfct[i-1]*rev(i)%mod;
	scanf("%d",&n);
	al = 1;
	for (int i=1;i<=n;i++) al = al*rev(2)%mod;
	for (int i=1;i<=n;i++) scanf("%d",x+i),bg[x[i]]++;
	sort(bg+1,bg+n+1,cmp);
	gen(1,0);
	for (int i=1;i<=idx;i++) a[i][i] = mod-1,a[i][idx+1]=-1;
	a[s][idx+1] = (a[s][idx+1]-1+mod)%mod;
	for (int u=1;u<=idx;u++)
	{
		for (int i=1;i<=n;i++) cur[i] = sta[u][i];
		dfs1(1,0,al,u);
	}
	gause(ans);
	printf("%lld",ans[t]);
	return 0;
}
