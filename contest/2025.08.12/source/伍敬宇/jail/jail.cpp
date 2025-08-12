#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
const int MAXN = 1.2e5 + 12;
const int SIZE = 1<<21;
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
int n,m;
int head[MAXN],to[MAXN<<1],nxt[MAXN<<1],cnt;
int s[MAXN],t[MAXN];
int fa[MAXN],sum[MAXN],hson[MAXN],top[MAXN],dfn[MAXN],p[MAXN],idx,dep[MAXN];
inline void add(const int&u,const int&v)
{
	cnt++;
	to[cnt] = v;
	nxt[cnt] = head[u];
	head[u] = cnt;
}
void dfs1(int u,int f)
{
	fa[u] = f;
	dep[u] = dep[f] + 1;
	sum[u] = 1;
	hson[u] = 0;
	for (int i=head[u];i;i=nxt[i])
	{
		int v = to[i];
		if (v==f) continue ;
		dfs1(v,u);
		if (sum[v]>sum[hson[u]]) hson[u] = v;
		sum[u] += sum[v];
	}
}
void dfs2(int u,int tp)
{
	dfn[u] = ++idx;
	p[idx] = u;
	top[u] = tp;
	if (hson[u]==0) return ;
	dfs2(hson[u],tp);
	for (int i=head[u];i;i=nxt[i])
	{
		int v = to[i];
		if (v==fa[u]||v==hson[u]) continue ;
		dfs2(v,v);
	}
}
struct SegTreeNode{
	int lc,rc;
}T[MAXN<<1];
vector<int> E[MAXN<<3];
int sz,pos[MAXN];
void build(int k,int l,int r)
{
	if (l==r)
	{
		pos[p[l]] = k;
		return ;
	}
	int md = (l+r)>>1;
	T[k].lc = ++sz,T[k].rc = ++sz;
	build(T[k].lc,l,md),build(T[k].rc,md+1,r);
	E[T[k].lc*2-1].push_back(k*2-1),E[T[k].rc*2-1].push_back(k*2-1);
	E[k*2].push_back(T[k].lc*2),E[k*2].push_back(T[k].rc*2);
}
void sadd1(int k,int l,int r,int L,int R,int tar)
{
	if (r<L||l>R) return ;
	if (L<=l&&r<=R)
	{
		E[k*2-1].push_back(tar);
		return ;
	}
	int md = (l+r)>>1;
	sadd1(T[k].lc,l,md,L,R,tar),sadd1(T[k].rc,md+1,r,L,R,tar);
}
void sadd2(int k,int l,int r,int L,int R,int tar)
{
	if (r<L||l>R) return ;
	if (L<=l&&r<=R)
	{
		E[tar].push_back(k*2);
		return ;
	}
	int md = (l+r)>>1;
	sadd2(T[k].lc,l,md,L,R,tar),sadd2(T[k].rc,md+1,r,L,R,tar);
}
void atree1(int u,int v,int tar)
{
	bool fu=1,fv=0;
	while (top[u]!=top[v])
	{
		if (dep[top[u]]<dep[top[v]]) swap(u,v),swap(fu,fv);
		if(fu==0) sadd1(1,1,n,dfn[top[u]],dfn[u],tar);
		else fu=0,sadd1(1,1,n,dfn[top[u]],dfn[fa[u]],tar);
		u = fa[top[u]];
	}
	if (dep[u]>dep[v]) swap(u,v),swap(fu,fv);
	if (fu) sadd1(1,1,n,dfn[u]+1,dfn[v],tar),fu = 0;
	else if (fv) sadd1(1,1,n,dfn[u],dfn[v]-1,tar),fv = 0;
	else sadd1(1,1,n,dfn[u],dfn[v],tar);
}
void atree2(int u,int v,int tar)
{
	bool fu=0,fv=1;
	while (top[u]!=top[v])
	{
		if (dep[top[u]]<dep[top[v]]) swap(u,v),swap(fu,fv);
		if(fu==0) sadd2(1,1,n,dfn[top[u]],dfn[u],tar);
		else fu=0,sadd2(1,1,n,dfn[top[u]],dfn[fa[u]],tar);
		u = fa[top[u]];
	}
	if (dep[u]>dep[v]) swap(u,v),swap(fu,fv);
	if (fu) sadd2(1,1,n,dfn[u]+1,dfn[v],tar),fu = 0;
	else if (fv) sadd2(1,1,n,dfn[u],dfn[v]-1,tar),fv = 0;
	else sadd2(1,1,n,dfn[u],dfn[v],tar);
}
queue<int> q;
int deg[MAXN<<3];
bool topo()
{
	while (!q.empty()) q.pop();
	for (int i=1;i<=sz*2+m;i++) deg[i] = 0;
	for (int i=1;i<=sz*2+m;i++)
	{
		for (int j=0;j<E[i].size();j++)
			deg[E[i][j]] ++;
	}
	for (int i=1;i<=sz*2+m;i++)
		if (deg[i]==0) q.push(i);
	int cnt = 0;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		cnt++;
		for (int i=0;i<E[u].size();i++)
		{
			int v = E[u][i];
			deg[v]--;
			if (deg[v]==0) q.push(v);
		}
	}
	return cnt>=sz*2+m;
}
void work()
{
	n = read();
	cnt = 0;
	for (int i=1;i<=n;i++) head[i] = 0;
	for (int i=0;i<=n*5+10;i++) E[i].clear();
	for (int i=1;i<n;i++)
	{
		int u = read(),v = read();
		add(u,v),add(v,u);
	}
	idx = 0;
	dep[0] = 0;
	dfs1(1,0);
	dfs2(1,1);
	sz = 1;
	build(1,1,n);
	m = read();
	for (int i=1;i<=m;i++)
	{
		s[i] = read(),t[i] = read();
		atree1(s[i],t[i],i+sz*2);
		atree2(s[i],t[i],i+sz*2);
		E[i+sz*2].push_back(pos[s[i]]*2-1);
		E[pos[t[i]]*2].push_back(i+sz*2);
	}
	if (topo()) printf("Yes\n");
	else printf("No\n");
}
int main()
{
	freopen("jail.in","r",stdin);
	freopen("jail.out","w",stdout);
	int t = read();
	while (t--) work();
	return 0;
}
