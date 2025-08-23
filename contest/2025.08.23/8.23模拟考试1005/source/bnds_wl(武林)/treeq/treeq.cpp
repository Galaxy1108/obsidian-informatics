#include <cstdio>
#include <iostream>
#include <unordered_map>

using namespace std;
typedef long long ll;

char buf[1<<23],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
inline int rd() {
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
	return x*f;
}
struct edge
{
	int to;
	int val;
	int next;
}e[20000005];
int head[10000005], cnt = 0, sz[10000005], n, ans[10000005], fev[10000005];
unordered_map<ll, int> ump;
ll b1[10000005], b2[10000005], now1, now2, val[10000005];
void add_edge(int u, int v, int w)
{
	++cnt;
	e[cnt].to = v;
	e[cnt].val = w;
	e[cnt].next = head[u];
	head[u] = cnt;
}
void dfs(int x, int y)
{
	int i;
	ll v;
	sz[x] = 1;
	for(i = head[x]; i; i = e[i].next)
		if(e[i].to != y)
		{
			fev[e[i].to] = e[i].val;
			dfs(e[i].to, x);
			sz[x] += sz[e[i].to];
			v = max(b1[e[i].to], 1ll * e[i].val * sz[e[i].to]);
			if(v > b1[x])
			{
				b2[x] = b1[x];
				b1[x] = v;
			}
			else if(v > b2[x])
				b2[x] = v;
		}
}
void dfs2(int x, int y)
{
	int i, c1, c2;
	ll p1, p2, v;
	p1 = now1;
	p2 = now2;
	val[x] = max(max(p1, b1[x]), p2);
	c1 = ump[1ll * fev[x] * sz[x]];
	c2 = ump[1ll * fev[x] * (n - sz[x])];
	ump[val[x]]++;
	for(i = head[x]; i; i = e[i].next)
		if(e[i].to != y)
		{
			v = max(b1[e[i].to], 1ll * e[i].val * sz[e[i].to]);
			now1 = max(p1, ((v == b1[x]) ? b2[x] : b1[x]));
			now2 = max(p2, 1ll * e[i].val * (n - sz[e[i].to]));
			dfs2(e[i].to, x);
		}
	c1 = ump[1ll * fev[x] * sz[x]] - c1;
	c2 = ump[1ll * fev[x] * (n - sz[x])] - c2;
	ans[x] += c2 - c1;
	now1 = p1;
	now2 = p2;
}

int main()
{
	freopen("treeq.in", "r", stdin);
	freopen("treeq.out", "w", stdout);
	int i, f, w, as = 0;
	n = rd();
	for(i = 2; i <= n; i++)
	{
		f = rd();
		w = rd();
		add_edge(f, i, w);
	}
	dfs(1, 0);
	dfs2(1, 0);
	for(i = 1; i <= n; i++)
		ans[i] += ump[1ll * fev[i] * sz[i]];
	for(i = 2; i <= n; i++)
		as ^= ans[i];
	printf("%d\n", as);
	return 0;
}