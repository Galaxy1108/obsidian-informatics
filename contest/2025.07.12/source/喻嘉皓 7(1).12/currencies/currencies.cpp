#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
const int N=100010;
int n,m,q;
struct Line{
	int u,v,w;
}L[N];
struct To{
	int v,id;
};
vector<To> g[N];
vector<int> cost[N];
struct PER{
	int s,t,x,y;
}mem[N];
int fa[N],dep[N],size[N],son[N],inl[N],idl[N],tot2,zhuan[N];
int sonl[N];
int dfn[N],tot,top[N];
void dfs1(int s,int f){
	fa[s]=f; size[s]=1; dep[s]=dep[f]+1; 
	for(To to:g[s]){
		if(to.v==f) continue;
		inl[to.v]=to.id;
		dfs1(to.v,s);
		if(size[to.v]>size[son[s]]) son[s]=to.v,sonl[s]=to.id;;
		size[s]+=size[to.v];
	}
}
void dfs2(int s,int Top,int in){
	top[s]=Top; dfn[s]=++tot;//重编号便于线段树操作 
	idl[in]=tot; zhuan[tot]=in;
	if(son[s]) dfs2(son[s],Top,sonl[s]);
	for(To to:g[s]){
		if(to.v==fa[s]||to.v==son[s]) continue;
		dfs2(to.v,to.v,to.id);
	}
}
int LCA(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		x=fa[top[x]];
	}
	if(dep[x]<dep[y]) swap(x,y);
	return y;
}
int road[N],tmp[N];
struct node1{
	int l,r,mid;
	int dat;//储存每个边上有几个收费点 
}d[4*N];
#define ls(p) (p<<1)
#define rs(p) ((p<<1)+1)
void up1(int p){
	d[p].dat=d[ls(p)].dat+d[rs(p)].dat;
}
void build1(int l,int r,int p){
	int mid=l+(r-l)/2;
	d[p].l=l; d[p].r=r; d[p].mid=mid;
	if(l==r){
		d[p].dat=cost[zhuan[l]].size();//代表这一条边上收费点数 
		return;
	}
	build1(l,mid,ls(p));
	build1(mid+1,r,rs(p));
	up1(p);
}
int getd(int s,int t,int p){
	if(s<=d[p].l&&d[p].r<=t){
		return d[p].dat;
	}
	int sum=0;
	if(s<=d[p].mid) sum+=getd(s,t,ls(p));
	if(t>d[p].mid) sum+=getd(s,t,rs(p));
	return sum;
}
int getp(int x,int y){
	int sum=0;
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		sum+=getd(dfn[top[x]],dfn[x],1);
		x=fa[top[x]];
	}
	if(dep[x]<dep[y]) swap(x,y);
	sum+=getd(dfn[y]+1,dfn[x],1);
	return sum;
}
signed main(){
	freopen("currencies.in","r",stdin);
	freopen("currencies.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m>>q;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].pb({v,i});
		g[v].pb({u,i});
		L[i].u=u; L[i].v=v;
	}
	bool flag1=0;
	int _cost=0;
	for(int i=1;i<=m;i++){
		int id,w;
		cin>>id>>w;
		if(_cost==0) _cost=w;
		else if(_cost!=w) flag1=0;
		cost[id].pb(w);
	}
	for(int i=1;i<=q;i++){
		int s,t,x,y;
		cin>>s>>t>>x>>y;
		mem[i].s=s; mem[i].t=t;
		mem[i].x=x; mem[i].y=y;
	}
	dfs1(1,0);
	dfs2(1,1,0);
	if(flag1) build1(1,n-1,1);
	for(int i=1;i<=q;i++){
		int s=mem[i].s,t=mem[i].t;
		int lca=LCA(s,t);
		if(dep[s]-dep[lca]+dep[t]-dep[lca]<=2e3){
			queue<int> q;
			stack<int> k;
			for(int j=s;j!=lca;j=fa[j]) q.push(j);
			for(int j=t;j!=lca;j=fa[j]) k.push(j);
			int all=0;
			while(!q.empty()){
				road[++all]=q.front(); q.pop();
			}
			road[++all]=lca;
			while(!k.empty()){
				road[++all]=k.top(); k.pop();
			}
			int cnt=0;
			for(int j=1;j<=all;j++){
				if(road[j]==lca) continue;
				for(int k:cost[inl[road[j]]]){
					tmp[++cnt]=k;
				}
			}
			sort(tmp+1,tmp+cnt+1);
			int sum=0,cut=0;
			for(int j=1;j<=cnt;j++){
				if(sum+tmp[j]>mem[i].y) break;
				sum+=tmp[j]; cut++;
			}
			int gold=cnt-cut;
			if(gold<=mem[i].x) cout<<mem[i].x-gold<<'\n';
			else cout<<-1<<'\n';			
		}
		else if(flag1){
			int sum=getp(s,t);
			int cut=mem[i].y/_cost;
			int left=sum-cut;
			if(left<=mem[i].x) cout<<mem[i].x-left<<'\n';
			else cout<<-1<<'\n';
		}
	}
	return 0;
}

