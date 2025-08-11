#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 1e3 + 12;
const int SIZE = 1<<21;
char buf[SIZE+1],*iS,*iT;
long long f[MAXN][MAXN];
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
int n,m,a[MAXN],b[MAXN];
long long dp[MAXN][MAXN];
int main()
{
	freopen("kyoto.in","r",stdin);
	freopen("kyoto.out","w",stdout);
	n = read(),m = read();
	for (int i=1;i<=n;i++) a[i] = read();
	for (int i=1;i<=m;i++) b[i] = read();
	memset(dp,0x3f3f3f3f,sizeof(dp));
	dp[1][1] = 0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			if (i>1) dp[i][j] = min(dp[i][j],dp[i-1][j]+b[j]);
			if (j>1) dp[i][j] = min(dp[i][j],dp[i][j-1]+a[i]);
		}
	printf("%lld",dp[n][m]);
	return 0;
}
