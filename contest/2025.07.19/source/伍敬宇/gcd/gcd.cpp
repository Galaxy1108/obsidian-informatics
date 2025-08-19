#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
const int SIZE = 1<<21,MAXN = 1e6 + 12;
char buf[SIZE+1],*iS,*iT;
inline char mget()
{
	if (iS==iT) iS = buf,iT = buf + fread(buf,1,SIZE,stdin);
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
int p[MAXN],b[MAXN],mu[MAXN],cnt;
long long smu[MAXN];
void init()
{
	int n = 1e6;
	b[1] = 1;
	mu[1] = 1;
	for (register int i=2;i<=n;i++)
	{
		if (b[i]==0) mu[i]=-1,p[++cnt] = i;
		for (register int j=1;j<=cnt&&i*p[j]<=n;j++)
		{
			b[i*p[j]] = 1;
			if (i%p[j]==0)
			{
				mu[i*p[j]] = 0;
				break;
			}
			else mu[i*p[j]] = -mu[i];
		}
	}
	for (register int i=1;i<=n;i++)
		smu[i] = smu[i-1] + mu[i]; 
}
long long cal(register int n,register int m)
{
	if (n==0||m==0) return 0;
	register int l,r;
	register long long res = 0;
	for (l=1;l<=n&&l<=m;l=r+1)
	{
		r = min(n/(n/l),m/(m/l));
		res += (smu[r]-smu[l-1])*(1ll*n/l)*(1ll*m/l);
	}
	return res;
}
int main()
{
	freopen("gcd.in","r",stdin);
	freopen("gcd.out","w",stdout);
	init();
	int t = read();
	while (t--)
	{
		int a=read(),b=read(),c=read(),d=read(),k=read();
		printf("%lld\n",cal(b/k,d/k)-cal((a-1)/k,d/k)-cal(b/k,(c-1)/k)+cal((a-1)/k,(c-1)/k));
	}
	return 0;
}
