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
	int fa[200010],siz[200010];
	void init(int n){for(int i=1;i<=n;i++) fa[i]=i,siz[i]=1;}
	int get_fa(int a){return a==fa[a]?a:fa[a]=get_fa(fa[a]);}
	bool merge(int u,int v)
	{
		if((u=get_fa(u))==(v=get_fa(v))) return true;
		if(siz[u]<siz[v]) fa[u]=v,siz[v]+=siz[u];
		else fa[v]=u,siz[u]+=siz[v];
		return false;
	}
}
template <typename T>void get_max(T &a,T b){if(a<b) a=b;}
typedef pair<int,int> pr;
vector<int> ed[200010];
void add_edge(int u,int v)
{
	ed[u].push_back(v);
	ed[v].push_back(u);
}
vector<pr> spc;
int n;
int a[200010],h[200010],c[200010];
int fa[200010];bool hb[200010];
int tot,num[200010];int lim;
void dfs(int a,int fa)
{
	::fa[a]=fa;
	num[++tot]=h[a];
	for(int v:ed[a])
		if(v!=fa)
			dfs(v,a);
}
long long cnt[200010],tmp,ans;
#define ls s[pos].lson
#define rs s[pos].rson
#define mid (l+r>>1)
namespace Sege{
	struct Node{
		int lson,rson;
		long long maxn,mxlaz,add_laz;
	}s[8000010];
	int poi_cnt;
	void reset(){memset(s,0,sizeof(Node)*(poi_cnt+1));poi_cnt=0;}
	void giv_laz(int pos,long long mx,long long ad)
	{
		s[pos].maxn=max(s[pos].maxn,mx)+ad;
		mx-=s[pos].add_laz;
		get_max(s[pos].mxlaz,mx);
		s[pos].add_laz+=ad;
	}
	void pushdown(int pos)
	{
		if(s[pos].mxlaz||s[pos].add_laz)
		{
			if(!ls) ls=++poi_cnt;
			giv_laz(ls,s[pos].mxlaz,s[pos].add_laz);
			if(!rs) rs=++poi_cnt;
			giv_laz(rs,s[pos].mxlaz,s[pos].add_laz);
			s[pos].mxlaz=s[pos].add_laz=0;
		}
	}
	void update(int pos)
	{
		s[pos].maxn=max(s[ls].maxn,s[rs].maxn);
	}
	void range_num(int L,int R,long long num,int &pos,int l=1,int r=lim)
	{
		if(r<L||R<l) return;
		if(!pos) pos=++poi_cnt;
		if(L<=l&&r<=R) return giv_laz(pos,num,0);
		return pushdown(pos),range_num(L,R,num,ls,l,mid),range_num(L,R,num,rs,mid+1,r),update(pos);
	}
	long long range_maxn(int x,int &pos,int l=1,int r=lim)
	{
		if(l==r) return s[pos].maxn;
		pushdown(pos);
		if(x<=mid) return range_maxn(x,ls,l,mid);
		else return range_maxn(x,rs,mid+1,r);
	}
	void merge(int &pos1,int pos2,int l=1,int r=lim)
	{
		if(pos1&&pos2)
		{
			if(l==r)
			{
				s[pos1].maxn+=s[pos2].maxn;
				s[pos1].mxlaz+=s[pos2].mxlaz;
				s[pos1].add_laz+=s[pos2].add_laz;
			}
			else
			{
				if(!s[pos1].lson&&!s[pos1].rson) swap(pos1,pos2);
				if(!s[pos2].lson&&!s[pos2].rson) giv_laz(pos1,0,s[pos2].maxn);
				else
				{
					pushdown(pos1),pushdown(pos2);
					merge(s[pos1].lson,s[pos2].lson,l,mid);
					merge(s[pos1].rson,s[pos2].rson,mid+1,r);
					update(pos1);
				}
			}
		}
		else pos1+=pos2;
	}
	void get_ans(int pos,int l=1,int r=lim)
	{
		if(l==r) get_max(ans,s[pos].maxn+cnt[l]);
		else pushdown(pos),get_ans(ls,l,mid),get_ans(rs,mid+1,r);
	}
	void show(int pos,int l=1,int r=lim)
	{
		if(!pos) return;
		printf("%d %d %d[%d %d]:%lld %lld %lld\n",pos,l,r,ls,rs,s[pos].maxn,s[pos].mxlaz,s[pos].add_laz);
		show(ls,l,mid),show(rs,mid+1,r);
	}
}
#undef ls
#undef rs
#undef mid
int RT,rt[200010];
void solve(int a,int fa)
{
	h[a]=lower_bound(num+1,num+lim+1,h[a])-num;
	if(hb[a])
	{
		cnt[h[a]]+=c[a];
		for(int v:ed[a])
			if(v!=fa)
			{
				solve(v,a);
				if(!hb[v])
					Sege::merge(RT,rt[v]);
			}
	}
	else
	{
		for(int v:ed[a])
			if(v!=fa)
			{
				solve(v,a);
				Sege::merge(rt[a],rt[v]);
			}
		// Sege::show(rt[a]);

		tmp=Sege::range_maxn(h[a],rt[a])+c[a];
		
		Sege::range_num(1,h[a],tmp,rt[a]);

		// Sege::show(rt[a]);
		// printf("------\n");
	}
}
long long finans;
int main()
{
	freopen("reporter.in","r",stdin);
	freopen("reporter.out","w",stdout);
	n=Qread();
	for(int i=1;i<=n;i++)
		a[i]=Qread(),h[i]=Qread(),finans+=(c[i]=Qread());
	DSU::init(n);
	for(int i=1;i<=n;i++)
		if(DSU::merge(i,a[i])) spc.push_back(make_pair(i,a[i]));
		else add_edge(i,a[i]);
	for(pr &E:spc)
	{
		tot=RT=0;
		dfs(E.first,0);
		sort(num+1,num+tot+1);
		lim=unique(num+1,num+tot+1)-num-1;
		Sege::reset();
		memset(cnt,0,(lim+1)<<3);

		for(int cur=E.second;cur!=E.first;cur=fa[cur]) hb[cur]=true;
		hb[E.first]=true;
		solve(E.first,0);
		ans=0;Sege::get_ans(RT);
		finans-=ans;
	}
	printf("%lld\n",finans);
	return 0;
}