#include <cstdio>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
const int MAXN = 1e5 + 12;
const int SIZE = 1<<21;
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
	while ('0'<=ch&&ch<='9') 
	{
		x = x*10 + ch - '0',ch = mget();
	}
	return x;
}
struct TreeNode{
	int sum,lc,rc;
	long long xsum;
}T[MAXN*96];
int sz;
void pushup(int k)
{
	T[k].sum = T[T[k].lc].sum + T[T[k].rc].sum;
	T[k].xsum = T[T[k].lc].xsum + T[T[k].rc].xsum;
}
int add(int k,int l,int r,int pos)
{
	int nk = ++sz;
	if (l==r)
	{
		T[nk].sum = T[k].sum + 1;
		T[nk].xsum = T[k].xsum + pos; 
		return nk;
	}
	int md = (l+r)>>1;
	if (pos<=md) T[nk].lc = add(T[k].lc,l,md,pos),T[nk].rc = T[k].rc;
	else T[nk].lc = T[k].lc,T[nk].rc = add(T[k].rc,md+1,r,pos);
	pushup(nk);
	return nk;
}
long long query(int k1,int k2,int k3,int l,int r,int pos) //k1 + k2 - 2*k3
{
	if (l==r) return 1ll*pos*l;
	int md = (l+r)>>1;
	if (pos<=T[T[k1].lc].sum+T[T[k2].lc].sum-2*T[T[k3].lc].sum) return query(T[k1].lc,T[k2].lc,T[k3].lc,l,md,pos);
	return T[T[k1].lc].xsum+T[T[k2].lc].xsum-2*T[T[k3].lc].xsum + query(T[k1].rc,T[k2].rc,T[k3].rc,md+1,r,pos-(T[T[k1].lc].sum+T[T[k2].lc].sum-2*T[T[k3].lc].sum));
}
int n,m,q;
int head[MAXN],to[MAXN<<1],nxt[MAXN<<1],cnt;
void adde(int u,int v)
{
	cnt++;
	to[cnt] = v;
	nxt[cnt] = head[u];
	head[u] = cnt;
}
int U[MAXN],V[MAXN],fa[MAXN],dfn[MAXN],st[MAXN][31],idx,dep[MAXN],rt[MAXN];
vector<int> val[MAXN];
inline int chs(int x,int y)
{
	if (dep[x]<dep[y]) return x;
	return y;
}
void init()
{
	for (int k=1;(1<<k)<=n;k++)
		for (int l=1;l+(1<<k)-1<=n;l++)
			st[l][k] = chs(st[l][k-1],st[l+(1<<(k-1))][k-1]);
}
int lca(int u,int v)
{
	if (dfn[u]>dfn[v]) swap(u,v);
	int k = log2(dfn[v]-dfn[u]);
	return fa[chs(st[dfn[u]+1][k],st[dfn[v]-(1<<k)+1][k])];
}
void dfs(int u,int f)
{
	dfn[u] = ++idx;
	st[idx][0] = u;
	fa[u] = f;
	dep[u] = dep[f] + 1;
	for (int i=head[u];i;i=nxt[i])
	{
		int v = to[i];
		if (v!=f) dfs(v,u);
	}
}
void cal(int u,int f)
{
	if (f==0) rt[u] = ++sz;
	else rt[u] = rt[f];
	for (int i=0;i<val[u].size();i++)
		rt[u] = add(rt[u],1,1e9,val[u][i]);
	for (int i=head[u];i;i=nxt[i])
	{
		int v = to[i];
		if (v==f) continue;
		cal(v,u);
	}
}
int main()
{
	freopen("currencies.in","r",stdin);
	freopen("currencies.out","w",stdout);
	n = read(),m = read(),q = read();
	for (int i=1;i<n;i++)
	{
		U[i] = read(),V[i] = read();
		adde(U[i],V[i]),adde(V[i],U[i]);
	}
	dfs(1,0);
	init();
	for (int i=1;i<=m;i++)
	{
		int p=read(),c=read();
		int u = U[p],v = V[p];
		if (fa[u]==v) val[u].push_back(c);
		else val[v].push_back(c);
	}
	cal(1,0);
	while (q--)
	{
		int u,v,x;
		long long y;
		u = read(),v = read(),x = read();
		y = read();
		int k1 = rt[u],k2 = rt[v],k3 = rt[lca(u,v)];
		int l = 0,r = T[k1].sum + T[k2].sum - 2*T[k3].sum,md,res=0;
		while (l<=r)
		{
			int md = (l+r)>>1;
			if (query(k1,k2,k3,1,1e9,md)<=y) res = md,l = md+1;
			else r = md-1;
		}
		int cst = T[k1].sum + T[k2].sum - 2*T[k3].sum - res;
		if (cst>x) printf("-1\n");
		else printf("%d\n",x - cst);
	}
	return 0;
}
