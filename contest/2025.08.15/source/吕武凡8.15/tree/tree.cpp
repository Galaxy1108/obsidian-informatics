#include<bits/stdc++.h>
using namespace std;
//#define int long long
int n,m,mod;
int dep[500010],siz[500010],son[500010],fa[500010];
int id[500010],wt[500010],top[500010];
int w[500001];
int cnt=0;
int tot=0;
int res=0;
int root;
int head[500010];
struct Edge
{
	int nx,to;
}e[500001];
void edge(int u,int v)
{
	e[++tot].nx=head[u];
	e[tot].to=v;
	head[u]=tot;
}
struct tree
{
	int l,r,dat,add;
}s[500001];
void pushup(int p)
{
	s[p].dat=s[p*2].dat+s[p*2+1].dat;
}
void addtag(int p,int x)
{
	s[p].dat+=(s[p].r-s[p].l+1)*x;
	s[p].add+=x;
}
void pushdown(int p)
{
	if(s[p].add)
	{
		addtag(p*2,s[p].add);
		addtag(p*2+1,s[p].add);
		s[p].add=0;
	}
}
void build(int p,int l,int r)
{
	s[p].l=l;
	s[p].r=r;
	if(l==r)
	{
		s[p].dat=wt[l];
		return;
	}
	int mid=(l+r)/2;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	pushup(p);
	return;
}
void update(int p,int l,int r,int d)
{
	if(s[p].l>=l&&s[p].r<=r)
	{
		addtag(p,d);
		return;
	}
	pushdown(p);
	int mid=(s[p].l+s[p].r)/2;
	if(mid>=l)
	{
		update(p*2,l,r,d);
	}
	if(mid<r)
	{
		update(p*2+1,l,r,d);
	}
	pushup(p);
}
void query(int p,int l,int r)
{
	if(s[p].l>=l&&s[p].r<=r)
	{
		res+=s[p].dat;
		res%=mod;
		return;
	}
	pushdown(p);
	int mid=(s[p].l+s[p].r)/2;
	if(mid>=l)
	{
		query(p*2,l,r);
	}
	if(mid<r)
	{
		query(p*2+1,l,r);
	}
	return;
}
void dfs1(int s,int f,int deep)
{
	dep[s]=deep;
	fa[s]=f;
	siz[s]=1;
	int ms=-1;
	for(int i=head[s];i;i=e[i].nx)
	{
		int y=e[i].to;
		if(y==f)
		{
			continue;
		}
		dfs1(y,s,deep+1);
		siz[s]+=siz[y];
		if(siz[y]>ms)
		{
			son[s]=y;
			ms=siz[y];
		}
	}
}
void dfs2(int x,int topf)
{
	id[x]=++cnt;
	wt[cnt]=w[x];
	top[x]=topf;
	if(!son[x])
	{
		return;
	}
	dfs2(son[x],topf);
	for(int i=head[x];i;i=e[i].nx)
	{
		int y=e[i].to;
		if(y==fa[x]||y==son[x])
		{
			continue;
		}
		dfs2(y,y);
	}
}
int qrange(int x,int y)
{
	int ans=0;
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])
		{
			swap(x,y);
		}
		res=0;
		query(1,id[top[x]],id[x]);
		ans+=res;
		ans%=mod;
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])
	{
		swap(x,y);
	}
	res=0;
	query(1,id[x],id[y]);
	ans+=res;
	return ans%mod;
}
int qson(int x)
{
	res=0;
	query(1,id[x],id[x]+siz[x]-1);
	return res;
}
void updson(int x,int k)
{
	update(1,id[x],id[x]+siz[x]-1,k);
	return;
}
void updrange(int x,int y,int k)
{
	k%=mod;
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])
		{
			swap(x,y);
		}
		update(1,id[top[x]],id[x],k);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])
	{
		swap(x,y);
	}
	update(1,id[x],id[y],k);
}
/*signed main()
{
	cin>>n>>m>>root>>mod;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		edge(a,b);
		edge(b,a);
	}
	dfs1(root,0,1);
	dfs2(root,root);
	build(1,1,n);
	while(m--)
	{
		int k,x,y,z;
		cin>>k;
		if(k==1)
		{
			cin>>x>>y>>z;
			updrange(x,y,z);
		}
		else if(k==2)
		{
			cin>>x>>y;
			cout<<qrange(x,y)<<endl;
		}
		else if(k==3)
		{
			cin>>x>>y;
			updson(x,y);
		}
		else
		{
			cin>>x;
			cout<<qson(x)<<endl;
		}
	}
}*/
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n;
	int x;
}
