#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int SIZE = 1<<21;
const int MAXN = 3e5 + 12;
char buf[SIZE+1],*iS,*iT;
inline char mget()
{
	if (iS==iT) iS=buf,iT=buf+fread(buf,1,SIZE,stdin),*iT='E';
	return *(iS++);
}
inline int read()
{
	int x=0,f=1;
	char ch = mget();
	while (ch<'0'||ch>'9') f = (ch=='-')?-1:1,ch = mget();
	while ('0'<=ch&&ch<='9') x = x*10 + ch - '0',ch = mget();
	return x*f;
}
int n,m;
int x[MAXN];
long long dp[2000+12][2000+12];
long long f[MAXN][3];
void work1()
{
	for (int i=0;i<=n;i++)
		f[m+1][i] = -1e18;
	f[m+1][n] = 0;
	for (int i=m;i>=1;i--)
	{
		f[i][0] = f[i+1][1] + x[i];
		f[i][n] = f[i+1][n-1] - x[i];
		for (int j=1;j<n;j++)
			f[i][j] = max(f[i+1][j+1]+x[i],f[i+1][j-1]-x[i]);
	}
	long long ans = -1e18;
	for (int i=0;i<=n;i++)
		ans = max(ans,f[1][i]);
	printf("%lld\n",ans);
}
void work()
{
	n = read(),m = read();
	for (int i=1;i<=m;i++)
		x[i] = read();
	if (n<=2)
	{
		work1();
		return ;
	}
	for (int i=0;i<=n;i++)
		dp[m+1][i] = -1e18;
	dp[m+1][n] = 0;
	for (int i=m;i>=1;i--)
	{
		dp[i][0] = dp[i+1][1] + x[i];
		dp[i][n] = dp[i+1][n-1] - x[i];
		for (int j=1;j<n;j++)
			dp[i][j] = max(dp[i+1][j+1]+x[i],dp[i+1][j-1]-x[i]);
	}
	long long ans = -1e18;
	for (int i=0;i<=n;i++)
		ans = max(ans,dp[1][i]);
	printf("%lld\n",ans);
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int t = read();
	while (t--) work();
	return 0;
}
