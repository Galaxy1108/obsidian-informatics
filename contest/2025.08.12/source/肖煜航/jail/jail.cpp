#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
using namespace std;
const int N=120005;
int T;
int n,m,tot;
int s[N],t[N];
vector<int> e[N],a[N],b[N],g[N];
int dep[N],f[N];
int ind[N];
bool vis[N];
map<pair<int,int>,bool> yes;
void dfs(int u,int fa){
	dep[u]=dep[fa]+1;
	f[u]=fa;
	for(int v:e[u]){
		if(v==fa) continue;
		dfs(v,u);
	}
}
void solve(int i,int x){
	for(int v:a[x]){
		if(v==i) continue;
		if(yes[{v,i}]) continue;
		yes[{v,i}]=1;
		g[v].push_back(i);
		ind[i]++;
		tot++;
	}
	for(int v:b[x]){
		if(v==i) continue;
		if(yes[{i,v}]) continue;
		yes[{i,v}]=1;
		g[i].push_back(v);
		ind[v]++;
		tot++;
	}
}
bool DAG(){
	queue<int> q;
	for(int i=1;i<=n;i++){
		if(ind[i]==0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis[u]=1;
		for(int v:g[u]){
			ind[v]--;
			if(ind[v]==0) q.push(v);
		}
	}
	for(int i=1;i<=n;i++) if(!vis[i]) return 0;
	return 1;
}
int main(){
	freopen("jail.in","r",stdin);
	freopen("jail.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		tot=0;
		yes.clear();
		for(int i=1;i<=n;i++){
			e[i].clear();
			a[i].clear();
			b[i].clear();
			g[i].clear();
			ind[i]=0;
			vis[i]=0;
		}
		for(int i=1;i<n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			e[x].push_back(y);
			e[y].push_back(x);
		}
		scanf("%d",&m);
		for(int i=1;i<=m;i++){
			scanf("%d%d",&s[i],&t[i]);
			a[s[i]].push_back(i);
			b[t[i]].push_back(i);
		}
		dfs(1,0);
		for(int i=1;i<=m;i++){
			int x=s[i],y=t[i];
			if(dep[x]<dep[y]) swap(x,y);
			while(dep[x]>dep[y]){
				solve(i,x);
				x=f[x];
			}
			if(x==y){
				solve(i,y); 
				continue;
			}
			while(x!=y){
				solve(i,x);
				solve(i,y);
				x=f[x];
				y=f[y];
			}
			solve(i,x);
		}
		if(DAG()) puts("Yes");
		else puts("No");
	}
	return 0;
}
