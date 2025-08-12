#include <bits/stdc++.h>
using namespace std;
#define il inline
const int N=120005;
int n,m,s[N],t[N],tt[N];
struct edge
{
	int v,nxt;
}e[N<<1];
int head[N],et=0;
il void add(int u,int v)
{
	e[++et].v=v;
	e[et].nxt=head[u];
	head[u]=et;
}
namespace dsu {
int fa[N];
il void init(){for(int i=1;i<=n;i++)fa[i]=i;}
il int getf(int x){return fa[x]==x?x:fa[x]=getf(fa[x]);}
il int merge(int u,int v)
{
	u=getf(u),v=getf(v);
	if(u==v)return 0;
	fa[u]=v;
	return 1;
}
}
namespace seg {
#define ls (p<<1)
#define rs ((p<<1)|1)
#define mid ((l+r)>>1)
int t1[N<<2],t2[N<<2];
il void build(int p,int l,int r)
{
	t1[p]=t2[p]=0;
	if(l==r)return;
	build(ls,l,mid);build(rs,mid+1,r);
}
il void upd(int p,int l,int r,int k,int x)
{
	if(l==r){t1[p]+=x,t2[p]+=(x==1?1:0);return;}
	if(k<=mid)upd(ls,l,mid,k,x);
	else upd(rs,mid+1,r,k,x);
	t1[p]=t1[ls]+t1[rs];
	t2[p]=t2[ls]+t2[rs];
}
il int query1(int p,int l,int r,int L,int R)
{
	if(r<L||R<l)return 0;
	if(L<=l&&r<=R)return t1[p];
	return query1(ls,l,mid,L,R)+query1(rs,mid+1,r,L,R);
}
il int query2(int p,int l,int r,int L,int R)
{
	if(r<L||R<l)return 0;
	if(L<=l&&r<=R)return t2[p];
	return query2(ls,l,mid,L,R)+query2(rs,mid+1,r,L,R);
}
}
int top[N],dep[N],son[N],siz[N],id[N],idx=0,ff[N];
il void dfs1(int u,int fa)
{
	dep[u]=dep[fa]+1,siz[u]=1,ff[u]=fa;
	for(int i=head[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa)continue;
		dfs1(v,u);
		siz[u]+=siz[v];
		if(siz[son[u]]<siz[v])son[u]=v;
	}
}
il void dfs2(int u,int h)
{
	top[u]=h,id[u]=++idx;
	if(son[u])dfs2(son[u],h);
	for(int i=head[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==ff[u]||v==son[u])continue;
		dfs2(v,v);
	}
}
il int query(int u,int v)
{
	int sum1=0,sum2=0;
	while(top[u]!=top[v])
	{
		if(dep[top[u]]<dep[top[v]])swap(u,v);
		sum1+=seg::query1(1,1,n,id[top[u]],id[u]);
		sum2+=seg::query2(1,1,n,id[top[u]],id[u]);
		u=ff[top[u]];
	}
	if(dep[u]>dep[v])swap(u,v);
	sum1+=seg::query1(1,1,n,id[u],id[v]);
	sum2+=seg::query2(1,1,n,id[u],id[v]);
	if(sum1==0&&sum2>1)return 0;
	return 1;
}
il void solve()
{
	cin>>n;
	memset(e,0,sizeof e);
	memset(head,0,sizeof head);
	memset(son,0,sizeof son);
	memset(top,0,sizeof top);
	memset(ff,0,sizeof ff);
	memset(tt,0,sizeof tt);
	for(int i=1,u,v;i<n;i++)
	{
		cin>>u>>v;
		add(u,v);add(v,u);
	}
	int flag=0;
	dsu::init();
	idx=0;
	seg::build(1,1,n);
	dfs1(1,0);
	dfs2(1,1);
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>s[i]>>t[i];
//		if(tt[t[i]])flag=1;
		tt[t[i]]=1;
		seg::upd(1,1,n,id[s[i]],1);
		seg::upd(1,1,n,id[t[i]],-1);
//		if(!dsu::merge(s[i],t[i]))flag=1;
	}
	if(m==2){cout<<"Yes\n";return;}
	for(int i=1;i<=m;i++)
	{
		if(!query(s[i],t[i]))
		{
			flag=1;
			break;
		}
	}
	if(flag){cout<<"No\n";return;}
	cout<<"Yes\n";
}
int main()
{
	freopen("jail.in","r",stdin);
	freopen("jail.out","w",stdout);
	int T;
	cin>>T;
	while(T--)solve();
	return 0;
}

