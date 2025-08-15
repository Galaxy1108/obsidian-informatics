#include<bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
const int N=500010;
int n;
ll ans[N];
int fa1[N],fa2[N];
int w1[N],w2[N];
int A[N];
struct Line{
	int v,w;
};
bool operator<(Line x,Line y){
	return x.w>y.w;
}
vector<Line> g1[N],g2[N];
ll sumA[5010][5010];//表示路径A总和 
void track(int u,int s,int f,int now,ll sum){//树T2 
	sumA[u][s]=sum;
	for(Line to:g2[s]){
		if(to.v==f) continue;
		track(u,to.v,s,now+1,sum+now*A[to.v]);
	}
}
void init(){
	for(int i=1;i<=n;i++){
		track(i,i,i,1,0);
	}
}
ll dis[N];
bool vis[N]; 
void bfs1(int s){//树T1 
	queue<int> q;
	for(int i=1;i<=n;i++) dis[i]=1e18,vis[i]=0;
	dis[s]=0; 
	q.push(s); vis[s]=1;
	while(!q.empty()){
		int now=q.front(); q.pop();
		for(Line to:g1[now]){
			if(vis[to.v]) continue;
			vis[to.v]=1;
			dis[to.v]=dis[now]+to.w;
			q.push(to.v);
		}
	}
}
void dfs2(int s,int u){//遍历树T2中u的子树 
	ans[u]=max(ans[u],dis[s]+sumA[s][u]);
	for(Line to:g2[s]){
		if(to.v==fa2[s]) continue;
		dfs2(to.v,u);
	}
}
void solve(int s){
	bfs1(s);
	dfs2(s,s);
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=2;i<=n;i++) cin>>fa1[i];
	for(int i=2;i<=n;i++){
		cin>>w1[i];
		g1[fa1[i]].pb({i,w1[i]});
		g1[i].pb({fa1[i],w1[i]});
	}
	for(int i=2;i<=n;i++){
		cin>>fa2[i];
		g2[fa2[i]].pb({i,0});
		g2[i].pb({fa2[i],0});
	}
	for(int i=1;i<=n;i++) cin>>A[i];
	init();
	for(int i=1;i<=n;i++){
		solve(i);
		cout<<ans[i]<<' ';
	}
	return 0;
}

