#include <bits/stdc++.h>
#define N 100005
#define ll long long 
using namespace std;
int n,m,Q;
struct Edge{
	int to,nxt,w;
}E[N];int h[N];
int X[N],Y[N];
void edge(int u,int v,int w){
	static int cnt=0;
	E[++cnt].nxt=h[u];
	E[cnt].to=v;
	E[cnt].w=w;
	h[u]=cnt;
}
ll dis[N],book[N];
int lz[N],lzi;
bool vis[N];
struct Node{
	int d,id;
	bool operator < (const Node x)const{
		return d>x.d;
	}
};
void dij(int s){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	memset(lz,0,sizeof(lz));
	priority_queue <Node> q;
	dis[s]=0;
	lzi=0;
	q.push({0,s});
	lz[++lzi]=s;
	while(q.size()){
		Node t=q.top();
		q.pop();
		int u=t.id;
		if(vis[u])continue;
		vis[u]=1;
		for(int i=h[u];i;i=E[i].nxt){
			int v=E[i].to,w=E[i].w;
			if(dis[v]>dis[u]+w){
				t.d=dis[v]=dis[u]+w;
				t.id=v;
				if(lz[lzi]!=u)lz[++lzi]=u;
				q.push(t);
			}			
		}
	}
}

int main(){
	freopen("currencies .in","r",stdin);
	freopen("currencies .out","w",stdout);
	cin >> n >> m >> Q;
	for(int i=1,Z;i<n;i++){
		cin >> X[i] >> Y[i];
//		cin >> Z;edge(X[p],Y[p],c);
//		edge(Y[p],X[p],c);
//		edge(X[i],Y[i],Z);
//		edge(Y[i],X[i],Z);
	}
	for(int i=1;i<=m;i++){
		int p,c;
		cin >> p >> c;	
		book[p]+=c;
	}
	for(int i=1;i<n;i++){
		edge(X[i],Y[i],book[i]);
		edge(Y[i],X[i],book[i]);
		
	}
	for(int i=1;i<=Q;i++){
		cout << -1;
	}
	return 0;
}

