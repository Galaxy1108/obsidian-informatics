#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int SIZE = 1<<21;
const int MAXN = 5e5 + 12;
char buf[SIZE+1],*iS,*iT;
inline char mget()
{
	if (iS==iT) iS = buf,iT = buf + fread(buf,1,SIZE,stdin),*iT = 'E';
	return *(iS++); 
}
inline int read()
{
	int x = 0,f = 1;
	char ch = mget();
	while (ch<'0'||ch>'9') f = (ch=='-')?-1:1,ch = mget();
	while ('0'<=ch&&ch<='9') x = x*10 + ch - '0',ch = mget();
	return x*f;
}
int n,fa1[MAXN],fa2[MAXN],a[MAXN];
int head1[MAXN],to1[MAXN<<1],nxt1[MAXN<<1],cst1[MAXN<<1],cnt1;
int head2[MAXN],to2[MAXN<<1],nxt2[MAXN<<1],cnt2;
long long ans[MAXN],dis[5000+12][5000+12];
inline void add1(int u,int v,int w)
{
	cnt1++;
	to1[cnt1] = v;
	cst1[cnt1] = w;
	nxt1[cnt1] = head1[u];
	head1[u] = cnt1;
}
inline void add2(int u,int v)
{
	cnt2++;
	to2[cnt2] = v;
	nxt2[cnt2] = head2[u];
	head2[u] = cnt2;
}
void dfs1(int u,int f,int st,long long cur)
{
	dis[st][u] = cur;
	for (int i=head1[u];i;i=nxt1[i])
	{
		int v = to1[i],w = cst1[i];
		if (v==f) continue ;
		dfs1(v,u,st,cur+w);
	}
}
long long voi(int u,int st,long long sum,long long cur)
{
	long long res = dis[st][u]+cur;
	for (int i=head2[u];i;i=nxt2[i])
	{
		int v = to2[i];
		res = max(res,voi(v,st,sum+a[v],cur+sum));
	}
	return res;
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	n = read();
	for (int i=2;i<=n;i++) fa1[i] = read();
	for (int i=2;i<=n;i++)
	{
		int w = read();
		add1(fa1[i],i,w);
		add1(i,fa1[i],w);
	}
	for (int i=2;i<=n;i++) fa2[i] = read(),add2(fa2[i],i);
	for (int i=1;i<=n;i++) a[i] = read();
	for (int i=1;i<=n;i++)
		dfs1(i,0,i,0);
	for (int i=1;i<=n;i++) ans[i] = voi(i,i,a[i],0);
	for (int i=1;i<=n;i++) printf("%lld ",ans[i]);
	return 0;
}
