#include<bits/stdc++.h>
using namespace std;
int n,cnt,tot,Ans;
int h[10000010],fa[10000010],w[10000010],siz[10000010],dfn[10000010];
int ans2[10000010];
long long val[10000010],ans[10000010];
struct Line{
	int v,nxt;
}line[10000010];
struct Val{
	long long x;
	int sum;
	Val operator +(const Val &a) const{
		if(x<a.x) return (Val){x,sum};
		if(a.x<x) return a;
		return (Val){x,sum+a.sum};
	}
}pre[10000010],suf[10000010],subt[10000010];
void Addline(int u,int v){
	line[++cnt].v=v,line[cnt].nxt=h[u],h[u]=cnt;
}
void dfs1(int x){
	siz[x]=1;dfn[x]=++tot;
	for(int i=h[x];i;i=line[i].nxt){
		int v=line[i].v;
		dfs1(v);
		val[x]=max(val[x],1ll*w[v]*siz[v]);
		val[x]=max(val[x],val[v]);
		siz[x]+=siz[v];
	}
}
void dfs2(int x,long long mx){
	ans[x]=max(val[x],mx);
	long long mx1=-1,mx2=-1;
	for(int i=h[x];i;i=line[i].nxt){
		int v=line[i].v;
		if(max(1ll*w[v]*siz[v],val[v])>mx1) mx2=mx1,mx1=max(1ll*w[v]*siz[v],val[v]);
		else if(max(1ll*w[v]*siz[v],val[v])>mx2) mx2=max(1ll*w[v]*siz[v],val[v]);
	}
	for(int i=h[x];i;i=line[i].nxt){
		int v=line[i].v;
		long long Mx=mx;

		if(max(1ll*w[v]*siz[v],val[v])==mx1) Mx=max(Mx,mx2);
		else Mx=max(Mx,mx1);
		Mx=max(Mx,1ll*(n-siz[v])*w[v]);
		dfs2(v,Mx);
	}
	return;
}
void Getans(int x){
	subt[x]=(Val){ans[x],1};
	for(int i=h[x];i;i=line[i].nxt){
		int v=line[i].v;
		Getans(v);
		subt[x]=subt[x]+subt[v];
	}
	if(x==1) return;
	int res=0;
	if(1ll*(n-siz[x])*w[x]==subt[x].x) res+=subt[x].sum;
	if(dfn[x]!=1&&1ll*siz[x]*w[x]==pre[dfn[x]-1].x) res+=pre[dfn[x]-1].sum;
	if(dfn[x]+siz[x]<=n&&1ll*siz[x]*w[x]==suf[dfn[x]+siz[x]].x) res+=suf[dfn[x]+siz[x]].sum;
	ans2[x]=res;
	Ans^=res;
	return;
}
int main()
{
	freopen("treeq.in","r",stdin);
	freopen("treeq.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=2;i<=n;++i){
		cin>>fa[i]>>w[i];
		Addline(fa[i],i);
	}
	dfs1(1);
	dfs2(1,-1);

	for(int i=1;i<=n;++i){
		pre[dfn[i]]=(Val){ans[i],1};
		suf[dfn[i]]=(Val){ans[i],1};
	}
	for(int i=2;i<=n;++i) pre[i]=pre[i]+pre[i-1];
	for(int i=n-1;i>=1;--i) suf[i]=suf[i]+suf[i+1];

	Getans(1);
	cout<<Ans<<'\n';

	return 0;
}
