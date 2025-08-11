#include <cstdio>
#include <iostream>
using namespace std;
const int SIZE = 1<<21;
const int MAXN = 5000 + 12;
const long long mod = 998244353;
char buf[SIZE+1],*iS,*iT;
char pbuf[SIZE+1],*pS=pbuf,*pT=pbuf+SIZE;
inline char mget()
{
	if (iS==iT) iS=buf,iT=buf+fread(buf,1,SIZE,stdin),*iT='E';
	return *(iS++);
}
inline int read()
{
	int x=0;
	char ch = mget();
	while (ch<'0'||ch>'9') ch = mget();
	while ('0'<=ch&&ch<='9') x = x*10 + ch - '0',ch = mget();
	return x;
}
inline void mput(const char&x)
{
	if (pS==pT) fwrite(pbuf,1,SIZE,stdout),pS = pbuf;
	*(pS++) = x;
}
inline void flush()
{
	fwrite(pbuf,1,pS-pbuf,stdout);
}
inline void write(int x)
{
	static char stk[33];
	static int top;
	if (x==0)
	{
		mput('0');
		return ;
	}
	top = 0;
	while (x) stk[++top] = x%10 + '0',x = x/10;
	while (top) mput(stk[top--]);
}
int n,m,l[MAXN],r[MAXN];
long long dp[MAXN][MAXN],ans[MAXN],rev[MAXN];
inline void upd(long long&x,long long y)
{
	x += y;
	if (x>=mod) x -= mod;
}
long long tr1[MAXN][MAXN],tr2[MAXN][MAXN];
void init()
{
	rev[1] = 1;
	for (int i=2;i<=n;i++)
		rev[i] = (mod-mod/i)*rev[mod%i]%mod;
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	n = read();
	init();
	for (int i=2;i<=n;i++)
		l[i] = read(),r[i] = read();
	m = read();
	for (int i=1;i<=m;i++)
	{
		int u = read(),v = read(),w = read()%mod;
		if (u==v) continue ;
		if (u>v) swap(u,v);
		upd(dp[v][u],w);
	}
	for (int v=n;v>=2;v--)
	{
		for (int u=v-1;u>=1;u--)
		{
			upd(tr2[v][u],tr2[v][u+1]);
			upd(tr1[v][u],tr1[v+1][u]);
			long long cur = dp[v][u] + tr1[v][u] + tr2[v][u];
			if (cur>=mod) cur -= mod;
			if (cur>=mod) cur -= mod;
			if (cur==0) continue ;
			upd(ans[v],cur);
			long long eff = rev[r[v]-l[v]+1]*cur%mod;
			long long ieff = mod - eff;
			if (l[v]>u)
			{
				upd(tr1[l[v]-1][u],ieff);
				upd(tr1[r[v]][u],eff);
			}
			else if (r[v]<u)
			{
				upd(tr2[u][l[v]-1],ieff);
				upd(tr2[u][r[v]],eff);
			}
			else 
			{
				upd(tr2[u][l[v]-1],ieff);
				upd(tr2[u][u-1],eff);
				upd(tr1[u][u],ieff),upd(tr1[r[v]][u],eff);
			}
		}
	}
	for (int i=2;i<n;i++)
		write(ans[i]),mput(' ');
	write(ans[n]);
	flush();
//	for (int i=2;i<n;i++)
//		printf("%lld ",ans[i]);
//	printf("%lld",ans[n]);
	return 0;
}
