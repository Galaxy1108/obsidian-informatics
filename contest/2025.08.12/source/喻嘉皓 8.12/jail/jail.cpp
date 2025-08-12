#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=120010;
int n,m;
bool flag1=1;
vector<int> g[N];
struct Per{
	int s,t,id;
	int lca;
	bool up,down;
}per[N];
bool cmp1(Per x,Per y){
	return x.s<=y.s;
}
bool cmp2(Per x,Per y){
	return x.t<=y.t;
}
void solve1(){
	sort(per+1,per+m+1,cmp1);
	for(int i=1;i<=m;i++){
		per[i].id=i;
	}
	sort(per+1,per+m+1,cmp2);
	for(int i=1;i<=m;i++){
		if(per[i].id!=i){
			cout<<"No\n";
			return;	
		}
	}
	cout<<"Yes\n";
	return;
} 
int fa[N],size[N],dep[N],son[N],tot;
int top[N],id[N];
void dfs1(int s,int f){
	fa[s]=f; dep[s]=dep[f]+1; size[s]=1;
	for(int to:g[s]){
		if(to==f) continue;
		dfs1(to,s);
		if(size[son[s]]<size[to]) son[s]=to;
		size[s]+=size[to];
	} 
}
void dfs2(int s,int Top){
	top[s]=Top; id[s]=++tot;
	if(son[s]) dfs2(son[s],Top);
	for(int to:g[s]){
		if(to==fa[s]||to==son[s]) continue;
		dfs2(to,to);
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
bool chkson(int x,int y){
	if(id[y]>=id[x]&&id[y]<=id[x]+size[x]-1) return true;
	else return false;
}
vector<int> g2[N];
bool solve2(){
	for(int i=1;i<=m;i++){
		for(int j=i+1;j<=m;j++){
			int l=i,r=j;
			int lcas=LCA(per[i].s,per[j].s);
			int lcat=LCA(per[i].t,per[j].t);
			if(lcas==per[i].s||lcas==per[j].s){//属于祖先关系 
				if(dep[per[i].s]<dep[per[j].s]) swap(l,r);
				if(dep[per[l].t]<=dep[per[r].t]) return false;
				if(per[l].up&&per[r].up&&dep[per[l].lca]<=dep[per[r].s]) g2[l].pb(r);//l到之前r得先到
				if(per[l].down&&per[r].down&&dep[per[r].t]>=dep[per[l].s]) g2[r].pb(l); 
				continue;
			}
			
		}
	} 
	return true; 
}
void init(){
	dfs1(1,0);
	dfs2(1,1);
	for(int i=1;i<=m;i++){
		per[i].lca=LCA(per[i].s,per[i].t);
		if(per[i].lca==per[i].s) per[i].down=1;
		else if(per[i].lca==per[i].t) per[i].up=1;
	}
}
void clear(){
	flag1=1;
	for(int i=1;i<=n;i++) g[i].clear();
}
int main(){
	freopen("jail.in","r",stdin);
	freopen("jail.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0) ;
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			if(u!=i||v!=i+1) flag1=0;
			g[u].pb(v);
			g[v].pb(u);
		}
		cin>>m;
		for(int i=1;i<=m;i++){
			cin>>per[i].s>>per[i].t;
		}
		if(flag1) solve1();
		else{
			init();
			if(solve2()) cout<<"Yes\n";
			else cout<<"No\n";
		}
		clear();
	}
	return 0;
}

