#include <bits/stdc++.h>
using namespace std;
int n,m,k,st;
vector<int> ed[400010];
namespace DSU{
	int fa[400010],siz[400010];
	void init(int n){for(int i=1;i<=n;i++) fa[i]=i,siz[i]=1;}
	int get_fa(int a){return a==fa[a]?a:fa[a]=get_fa(fa[a]);}
	void merge(int u,int v)
	{
		if((u=get_fa(u))==(v=get_fa(v))) return;
		if(siz[u]>siz[v]) fa[v]=u,siz[u]+=siz[v];
		else fa[u]=v,siz[v]+=siz[u];
	}
}
int u,v,l,r,mid,res;
int stk[100010],top;
bool find_gl(int a,int fa,int gl)
{
	stk[++top]=a;
	if(a==gl) return true;
	for(int v:ed[a]) if(v!=fa&&find_gl(v,a,gl))
		return true;
	return --top,false;
}
void solve()
{
	for(int i=1;i<=st;i++) vector<int>().swap(ed[i]);

	cin>>n>>m;
	k=((m+n-2)/(n-1));
	st=n*k;
	DSU::init(st);

	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		l=1,r=k,res=0;
		while(l<=r)
		{
			mid=(l+r>>1);
			if(DSU::get_fa(u+n*(mid-1))!=DSU::get_fa(v+n*(mid-1))) res=mid,r=mid-1;
			else l=mid+1;
		}
		if(res)
		{
			DSU::merge(u+n*(res-1),v+n*(res-1));
			ed[u+n*(res-1)].push_back(v+n*(res-1));
			ed[v+n*(res-1)].push_back(u+n*(res-1));
		}
	}

	for(int i=1;i<=n;i++) if(!ed[i+n*(k-1)].empty())
	{
		u=i,v=ed[i+n*(k-1)][0]-n*(k-1);
		break;
	}

	printf("%d %d\n",u,v);
	for(int i=1;i<=k;i++)
	{
		top=0;find_gl(u+n*(i-1),0,v+n*(i-1));

		printf("%d",top);
		for(int j=1;j<=top;j++)
			printf(" %d",stk[j]-n*(i-1));
		printf("\n");
	}
}
int main()
{
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
	return 0;
}