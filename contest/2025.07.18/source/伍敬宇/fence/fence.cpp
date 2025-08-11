#include <cstdio>
#include <algorithm>
using namespace std;
const int SIZE = 1<<21;
const int MAXN = 1e5 + 12;
const long long mod = 1e9 + 7;
const long long rev2 = (mod+1)/2;
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
int n,h[MAXN],w[MAXN];
int stk[MAXN],top,lb[MAXN],rb[MAXN];
int p[MAXN];
long long ans,sw[MAXN];
inline long long C2(long long x)
{
	return 1ll*x*(x-1)%mod*rev2%mod;
}
inline long long query(int l,int r)
{
	return (sw[r] - sw[l-1] + mod)%mod;
}
int main()
{
	freopen("fence.in","r",stdin);
	freopen("fence.out","w",stdout);
	n = read();
	for (int i=1;i<=n;i++) h[i] = read();
	for (int i=1;i<=n;i++) w[i] = read(),sw[i] = (sw[i-1]+w[i])%mod;
	for (int i=1;i<=n;i++)
	{
		while(top&&h[stk[top]]>=h[i]) top--;
		lb[i] = stk[top];
		stk[++top] = i;
	}
	top = 1;
	stk[top] = n+1;
	for (int i=n;i>=1;i--)
	{
		while(top&&h[stk[top]]>h[i]) top--;
		rb[i] = stk[top];
		stk[++top] = i;
	}
	for (int i=1;i<=n;i++)
	{
		long long x = C2(h[i] + 1);
		long long y = (query(lb[i]+1,i)*query(i,rb[i]-1)%mod - 1ll*w[i]*w[i]%mod + C2(w[i]+1) + mod)%mod;
		ans = (ans + x*y%mod)%mod;
	}
	printf("%lld",ans);
	return 0;
}
