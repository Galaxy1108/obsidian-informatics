#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXN = 2.5e6 + 12,SIZE = 1<<21;
const long long mod = 1e9 + 7;
char buf[SIZE],*iS,*iT;
inline char mget()
{
	if (iS==iT) iS = buf,iT = buf + fread(buf,1,SIZE,stdin);
	return *(iS++);
}
inline long long read()
{
	long long x = 0;
	char ch = mget();
	while (ch<'0'||ch>'9') ch = mget();
	while ('0'<=ch&&ch<='9') x = x*10 + ch - '0',ch = mget();
	return x;
}
int n,k;
int q[MAXN],l,r;
long long a[MAXN],s[MAXN];
inline void upd(long long&x,long long y)
{
	if (x>y) x = y;
}
int main()
{
	freopen("beetle.in","r",stdin);
	freopen("beetle.out","w",stdout);
	n = read(),k = read();
	for (int i=1;i<=n;i++) a[i] = read();
	for (int i=1;i<=n;i++)
	{
		s[i] = 1e18;
		while (l!=r&&a[q[r]]<=a[i]) r--;
		q[++r] = i;
		while (l!=r&&q[l+1]<=i-k) l++;
		for (int j=l+1;j<=r;j++)
		{
			if (j==l+1) upd(s[i],a[q[j]]+s[max(i-k,0)]);
			else upd(s[i],a[q[j]]+s[q[j-1]]);
		}
	}
	long long bas = 1,ans = 0;
	for (int i=n;i>=1;i--,bas=bas*23%mod)
	{
		ans = (ans + s[i]%mod*bas%mod)%mod;
	}
	printf("%lld",ans);
	return 0;
}
