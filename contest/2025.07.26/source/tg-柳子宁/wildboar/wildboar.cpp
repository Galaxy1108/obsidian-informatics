#include<bits/stdc++.h>
#define inf 1000000000000000000
using namespace std;
int n,m,Q,L,x,y;
int a[100010];
int u[2010],v[2010];
long long w[2010],dis[2010],tag[2010];
struct Line{
	int v,id;
};
struct Node{
	int x;
	long long dis;
	bool operator <(const Node &x) const{
		return dis>x.dis;
	}
};
priority_queue<Node> q;
vector<Line> line[2010];
long long D[4010][4010];
void Dijkstra(int x){
	for(int i=1;i<=n;++i) dis[i]=inf,tag[i]=0;
	dis[x]=0;q.push((Node){x,0});
	while(!q.empty()){
		Node p=q.top();
		q.pop();
		if(tag[p.x]) continue;
		for(auto l:line[p.x]){
			if(p.dis+w[l.id]<dis[l.v]){
				dis[l.v]=p.dis+w[l.id];
				q.push((Node){l.v,dis[l.v]});
			}
		}
	}
}
void solve(){
	long long ans=0;
	for(int i=2;i<=n;++i){
		Dijkstra(a[i-1]);
		ans+=dis[a[i]];
	}
	printf("%lld\n",ans);
}
int main()
{
	freopen("wildboar.in","r",stdin);
	freopen("wildboar.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&Q,&L);
	for(int i=1;i<=m;++i){
		scanf("%d%d%lld",&x,&y,&w[i]);
		u[i]=x,v[i]=y;
		line[x].push_back((Line){y,i});
		line[y].push_back((Line){x,i});
	}
	for(int i=1;i<=L;++i){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=Q;++i){
		scanf("%d%d",&x,&y);
		a[x]=y;
		solve();
	}
	return 0;
} 
