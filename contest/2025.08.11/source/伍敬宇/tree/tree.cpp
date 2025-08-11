#include <cstdio>
using namespace std;
const int MAXN = 5e5 + 12;
const int SIZE = 1<<21;
const double EPS = 3e-7;
char buf[SIZE+1],*iS,*iT;
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
int n,w[MAXN];
int head[MAXN],to[MAXN],nxt[MAXN],cnt;
double dp[MAXN],ans[MAXN];
inline void add(const int&u,const int&v)
{
	cnt++;
	to[cnt] = v;
	nxt[cnt] = head[u];
	head[u] = cnt;
}
void dfs(int u,double x)
{
	dp[u] = w[u] - x;
	for (int i=head[u];i;i=nxt[i])
	{
		int v = to[i];
//		if (ans[v]<x) continue ;
		dfs(v,x);
		if (dp[v]>0) dp[u] += dp[v]; 
	}
}
double solve(int s)
{
	if (head[s]==0) return w[s];
	double l = w[s],r = 1e9;
	double md,res=0;
	while (r-l>EPS)
	{
		md = l + (r-l)/2;
		dfs(s,md);
		if (dp[s]>=0) res = md,l = md;
		else r = md;
	}
	return res;
}
void work(int u)
{
	for (int i=head[u];i;i=nxt[i])
	{
		int v = to[i];
		work(v);
	}
	ans[u] = solve(u);
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	n = read();
	for (int i=2;i<=n;i++)
	{
		int f = read();
		add(f,i);
	}
	for (int i=1;i<=n;i++) w[i] = read();
	work(1);
	for (int i=1;i<=n;i++) printf("%.7lf\n",ans[i]);
	return 0;
}
