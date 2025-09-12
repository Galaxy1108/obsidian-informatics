#include <bits/stdc++.h>
using namespace std;
int Qread()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x;
}
namespace DSU{
	int fa[100010],siz[100010],mx[100010];
	void init(int n){for(int i=1;i<=n;i++) fa[i]=i,siz[i]=1;}
	int get_fa(int a){return a==fa[a]?a:fa[a]=get_fa(fa[a]);}
	void merge(int u,int v)
	{
		u=get_fa(u),v=get_fa(v);
		if(siz[u]>siz[v]) fa[v]=u,siz[u]+=siz[v],mx[u]=max(mx[u],mx[v]);
		else fa[u]=v,siz[v]+=siz[u],mx[v]=max(mx[v],mx[u]);
	}
};
struct Edge{
	int u,v,w;
}l[500010];
bool operator<(Edge A,Edge B){return A.w<B.w;}
int n,m,cnt;
int Z[100010];
vector<int> nd[100010];
int main()
{
	freopen("shattersong.in","r",stdin);
	freopen("shattersong.out","w",stdout);
	n=Qread(),m=Qread();
	for(int i=1;i<=n;i++) Z[i]=Qread();
	for(int i=1;i<=m;i++) l[i].u=Qread(),l[i].v=Qread(),l[i].w=Qread();
	DSU::init(n);

	sort(l+1,l+m+1);
	for(int i=1,u,v;i<=m;i++) if(DSU::get_fa(l[i].u)!=DSU::get_fa(l[i].v))
	{
		u=DSU::get_fa(l[i].u),v=DSU::get_fa(l[i].v);
		if(l[i].w<=min(DSU::mx[u]+Z[DSU::siz[u]],DSU::mx[v]+Z[DSU::siz[v]]))
		{
			DSU::merge(u,v);
			u=DSU::get_fa(u);
			DSU::mx[u]=max(DSU::mx[u],l[i].w);
		}
	}

	for(int i=1;i<=n;i++)
	{
		if(DSU::get_fa(i)==i) cnt++;
		nd[DSU::get_fa(i)].push_back(i);
	}

	printf("%d\n",cnt);
	for(int i=1;i<=n;i++) if(DSU::get_fa(i)==i)
	{
		printf("%d",(int)nd[i].size());
		for(int g:nd[i]) printf(" %d",g);
		printf("\n");
	}
	return 0;
}
