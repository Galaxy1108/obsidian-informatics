#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int SIZE = 1<<21;
const int MAXN = 2e5 + 12;
char buf[SIZE+2],*iS,*iT;
inline char mget()
{
	if (iS==iT) iS = buf,iT = buf + fread(buf,1,SIZE,stdin),*iT = 'E';
	return *(iS++);
}
inline int read()
{
	int x = 0;
	char ch = mget();
	while (ch<'0'||ch>'9') ch = mget();
	while ('0'<=ch&&ch<='9') x = x*10 + ch - '0',ch = mget();
	return x;
}
int n,fa[MAXN];
int head[MAXN],to[MAXN],nxt[MAXN],ecnt;
void adde(int u,int v)
{
	ecnt++;
	to[ecnt] = v;
	nxt[ecnt] = head[u];
	head[u] = ecnt;
}
int h[MAXN],c[MAXN];
int rt[MAXN];
int len;
long long dp[5000+12][5000+12];
void dfs(int u)
{
	long long sum = c[u];
	for (int i=head[u];i;i=nxt[i])
	{
		int v = to[i];
		dfs(v);
		for (int j=1;j<=len;j++)
		{
			dp[u][j] += dp[v][j];
		}
		sum += dp[v][h[u]];
	}
	for (int j=1;j<=h[u];j++)
		dp[u][j] = max(dp[u][j],sum);
}
int p[MAXN];
int main()
{
	freopen("reporter.in","r",stdin);
	freopen("reporter.out","w",stdout);
	long long sum = 0;
	n = read();
	for (int i=1;i<=n;i++)
	{
		fa[i] = read();
		if (i!=1) adde(fa[i],i);
		p[i] = h[i] = read(),c[i] = read();
		sum += c[i];
	}
	sort(p+1,p+n+1);
	len = unique(p+1,p+n+1) - p - 1;
	for (int i=1;i<=n;i++)
		h[i] = lower_bound(p+1,p+len+1,h[i]) - p;
	dfs(1);
	printf("%lld",sum - dp[1][1]);
	return 0;
}
