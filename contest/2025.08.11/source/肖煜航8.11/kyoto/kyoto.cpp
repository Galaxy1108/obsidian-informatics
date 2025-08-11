#include<cstdio>
#include<algorithm>
#include<queue>
#define ll long long
using namespace std;
const int N=1e6+5;
struct edge{
	int to,nxt;
	ll w;
}e[N<<1];
int head[N],tot;
void add(int u,int v,ll w){
	e[++tot]={v,head[u],w};
	head[u]=tot;
}
int n,m;
int get(int x,int y){
	return (x-1)*m+y;
}
bool vis[N];
ll dis[N];
void dij(){
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
	q.push({0,1});
	for(int i=1;i<=get(n,m);i++) dis[i]=1e18;
	dis[1]=0;
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].to;
			if(dis[v]>dis[u]+e[i].w){
				dis[v]=dis[u]+e[i].w;
				q.push({dis[v],v});
			}
		}
	}
}
int main(){
	freopen("kyoto.in","r",stdin);
	freopen("kyoto.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		for(int j=1;j<m;j++) add(get(i,j),get(i,j+1),x);
	}
	for(int j=1;j<=m;j++){
		int x;
		scanf("%d",&x);
		for(int i=1;i<n;i++) add(get(i,j),get(i+1,j),x);
	}
	dij();
	printf("%lld",dis[get(n,m)]);
	return 0;
}
