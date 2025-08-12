#include <bits/stdc++.h>
using namespace std;
int Qread()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x;
}
vector<int> ed[120010];
void add_edge(int u,int v)
{
	ed[u].push_back(v);
	ed[v].push_back(u);
}
namespace Graph{
	vector<int> ed[1000010];
	int lson[1000010],rson[1000010];
	int poi_cnt;
	void reset(int n)
	{
		for(int i=1;i<=poi_cnt;i++)
			vector<int>().swap(ed[i]);
		poi_cnt=n;
	}
	void add_edge(int u,int v){ed[u].push_back(v);}
	int cnt,rea,rd[1000010];
	queue<int> Q;
	bool chk_con()
	{
		memset(rd,0,(poi_cnt+1)<<2);
		for(int i=1;i<=poi_cnt;i++) for(int &v:ed[i]) rd[v]++;
		for(int i=1;i<=poi_cnt;i++) if(!rd[i]) Q.push(i);
		cnt=0;
		while(!Q.empty())
		{
			rea=Q.front();Q.pop();cnt++;
			for(int &v:ed[rea]) if(!(--rd[v])) Q.push(v);
		}
		return cnt==poi_cnt;
	}
	int ind[120010],oud[120010];
	#define mid ((l+r)>>1)
	void build_in_tree(int &pos,int l,int r)
	{
		pos=++poi_cnt;
		if(l<r)
		{
			build_in_tree(lson[pos],l,mid),build_in_tree(rson[pos],mid+1,r);
			add_edge(pos,lson[pos]),add_edge(pos,rson[pos]);
		}
		else ind[l]=pos;
	}
	void build_out_tree(int &pos,int l,int r)
	{
		pos=++poi_cnt;
		if(l<r)
		{
			build_out_tree(lson[pos],l,mid),build_out_tree(rson[pos],mid+1,r);
			add_edge(lson[pos],pos),add_edge(rson[pos],pos);
		}
		else oud[l]=pos;
	}
	void add_in_ed(int nd,int L,int R,int pos,int l,int r)
	{
		if(L<=l&&r<=R) return add_edge(nd,pos);
		if(r<L||R<l) return;
		return add_in_ed(nd,L,R,lson[pos],l,mid),add_in_ed(nd,L,R,rson[pos],mid+1,r);
	}
	void add_out_ed(int nd,int L,int R,int pos,int l,int r)
	{
		if(L<=l&&r<=R) return add_edge(pos,nd);
		if(r<L||R<l) return;
		return add_out_ed(nd,L,R,lson[pos],l,mid),add_out_ed(nd,L,R,rson[pos],mid+1,r);
	}
	#undef mid
}

struct Point{
	int siz,fa,dep,top;
	int bson,ind,R;
}p[120010];
int bk[120010];

void dfs1(int a,int fa)
{
	p[a].siz=1,p[a].fa=fa,p[a].dep=p[fa].dep+1,p[a].bson=0;
	for(int &v:ed[a])
	if(v!=fa)
	{
		dfs1(v,a);
		p[a].siz+=p[v].siz;
		if(p[p[a].bson].siz<p[v].siz) p[a].bson=v;
	}
}
int dfn;
void dfs2(int a,int top)
{
	p[a].top=top,p[a].ind=++dfn;bk[dfn]=a;
	if(p[a].bson) dfs2(p[a].bson,top);
	for(int &v:ed[a])
	if(v!=p[a].fa&&v!=p[a].bson)
		dfs2(v,v);
	p[a].R=dfn;
}
int get_kth_fa(int a,int k)
{
	int gl=p[a].dep-k;
	while(p[p[a].top].dep>gl) a=p[p[a].top].fa;
	return bk[p[a].ind-p[a].dep+gl];
}
int n,m;
int inrt,ourt;
int A[120010],B[120010];

void calc_in_ed(int u,int v,int nd)
{
	if(p[v].ind<=p[u].ind&&p[u].ind<=p[v].R) v=get_kth_fa(u,p[u].dep-p[v].dep-1); 
	else v=p[v].fa;
	while(p[u].top!=p[v].top)
	{
		if(p[p[u].top].dep<p[p[v].top].dep) swap(u,v);
		Graph::add_in_ed(nd,p[p[u].top].ind,p[u].ind,inrt,1,n),u=p[p[u].top].fa;
	}
	if(p[u].dep>p[v].dep) swap(u,v);
	Graph::add_in_ed(nd,p[u].ind,p[v].ind,inrt,1,n);
}
void calc_out_ed(int u,int v,int nd)
{
	if(p[u].ind<=p[v].ind&&p[v].ind<=p[u].R) u=get_kth_fa(v,p[v].dep-p[u].dep-1); 
	else u=p[u].fa;
	while(p[u].top!=p[v].top)
	{
		if(p[p[u].top].dep<p[p[v].top].dep) swap(u,v);
		Graph::add_out_ed(nd,p[p[u].top].ind,p[u].ind,ourt,1,n),u=p[p[u].top].fa;
	}
	if(p[u].dep>p[v].dep) swap(u,v);
	Graph::add_out_ed(nd,p[u].ind,p[v].ind,ourt,1,n);
}
void solve()
{
	dfn=0;
	for(int i=1;i<=n;i++)
		vector<int>().swap(ed[i]);
	n=Qread();
	for(int i=1;i<n;i++)
		add_edge(Qread(),Qread());
	m=Qread();
	for(int i=1;i<=m;i++)
		A[i]=Qread(),B[i]=Qread();

	Graph::reset(m);
	Graph::build_in_tree(inrt,1,n);
	Graph::build_out_tree(ourt,1,n);

	dfs1(1,0),dfs2(1,1);

	for(int i=1;i<=m;i++)
		Graph::add_edge(i,Graph::oud[p[A[i]].ind]),
		Graph::add_edge(Graph::ind[p[B[i]].ind],i),
		calc_out_ed(A[i],B[i],i),
		calc_in_ed(A[i],B[i],i);
	
	printf(Graph::chk_con()?"Yes\n":"No\n");

}
int main()
{
	freopen("jail.in","r",stdin);
	freopen("jail.out","w",stdout);
	int T=Qread();
	while(T--) solve();
	return 0;
}