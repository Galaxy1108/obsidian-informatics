#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define INF 9991145141919810
using namespace std;
const int N=2010;
struct Line{
	int u,w,v;
}l[N];
struct To{
	int v;
	ll w;
	int id;
}; 
bool operator<(To x,To y){
	return x.w>y.w;
}
vector<To> g[N];
int n,m,t,L;
int path[100010];
ll dis[N][N];
vector<ll> dist[N][N];
int las[N][N];//表示一个点到另一个点最短路最后经过的边 
vector<int> last[N][N]; 
bool vis[N];
void dij(int s){//处理出两两最短路距离 
	priority_queue<To> q;
	for(int i=1;i<=n;i++) dis[s][i]=INF,vis[i]=0;
	q.push({s,0,0});
	dis[s][s]=0;
	while(!q.empty()){
		To top=q.top(); q.pop();
		int u=top.v,from=top.id;
		if(vis[u]) continue;
		vis[u]=1; las[s][u]=from;
		for(To to:g[u]){
			int v=to.v,w=to.w,id=to.id;
			if(dis[s][v]>dis[s][u]+w){
				dis[s][v]=dis[s][u]+w;
				q.push({v,dis[s][v],id});
			}
		}
	}
}
void Dij(int s,int inl,int cnt){//处理出两两最短路距离(不过inl) 
	priority_queue<To> q;
	for(int i=1;i<=n;i++) dist[s][i][cnt]=INF,vis[i]=0;
	q.push({s,0,inl});
	dist[s][s][cnt]=0;
	while(!q.empty()){
		To top=q.top(); q.pop();
		int u=top.v,from=top.id;
		if(vis[u]) continue;
		vis[u]=1; last[s][u][cnt]=from;
		for(To to:g[u]){
			int v=to.v,w=to.w,id=to.id;
			if(id==from) continue;
			if(dist[s][v][cnt]>dist[s][u][cnt]+w){
				dist[s][v][cnt]=dist[s][u][cnt]+w;
				q.push({v,dist[s][v][cnt],id});
			}
		}
	}
}
int zhuan[N][N];
void init(){
	//n方量级 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dist[i][j].clear();
			last[i][j].clear();
		}
	}
	for(int i=1;i<=n;i++){
		for(To to:g[i]){
			int id=to.id;//表示不过这条边 
			for(int j=1;j<=n;j++){
				dist[i][j].pb(0);
				last[i][j].pb(0);
			}
			zhuan[i][id]=dist[i][i].size()-1;
			Dij(i,id,dist[i][i].size()-1);
		}
		dij(i);
	}
}
int main(){
	freopen("wildboar.in","r",stdin);
	freopen("wildboar.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m>>t>>L;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		l[i].u=u; l[i].v=v; l[i].w=w;
		g[u].pb({v,w,i});
		g[v].pb({u,w,i});
	}
	for(int i=1;i<=L;i++){
		int x;
		cin>>x;
		path[i]=x;
	}
	while(t--){
		init();
		bool bk=1;
		int p,q;
		cin>>p>>q;
		path[p]=q;
		ll sum=0;
		int from=0;
		for(int i=2;i<=L;i++){
			int u=path[i-1],v=path[i];
			if(i==2){
				sum+=dis[u][v];
				from=las[u][v];
			}
			else{
				int ls=(l[from].u==u?l[from].v:l[from].u);//获取上一个点
				int cnt=zhuan[u][from];//对应的是dist中的序号
				//从u点出发，不过from的最小值 
				if(dist[u][v][cnt]==INF){
					cout<<-1<<'\n';
					bk=0;
					break;
				}
				sum+=dist[u][v][cnt];//不过cnt这条边对应的最小值
				from=last[u][v][cnt]; 
			}
		}
		if(bk) cout<<sum<<'\n';
	}
	return 0;
}

