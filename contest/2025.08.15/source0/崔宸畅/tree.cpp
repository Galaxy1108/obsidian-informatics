#include<bits/stdc++.h>
using namespace std;
const int maxn=5e3+20;
int n,b[maxn],f[maxn],g[maxn],A;
int dis[maxn][maxn],diss[maxn][maxn];
struct pri{
	int ans,id;
	bool operator < (const pri &x) const{
		return x.ans<ans;
	}
};
struct Node{
	int to,nxt,w;
} edge[maxn*2];
int head[maxn*2],cnt,dep[maxn];
void add(int x,int y,int z){
	cnt++;
	edge[cnt].to=y;
	edge[cnt].w=z;
	edge[cnt].nxt=head[x];
	head[x]=cnt;
}
const int INF=0x3f;
vector<int> shortest[maxn];
bool S[maxn];
int eee[maxn][maxn],path[maxn],ans[maxn][maxn];
void Dijkstra(int s){
    memset(S,0,sizeof(S));
    for(int i=1;i<=n;i++){
        if(eee[s][i]<INF){
            dis[s][i]=eee[s][i];
            path[i]=s;
        }
        else{
            dis[s][i]=eee[s][i];
            path[i]=-1;
        }
    }
    S[s]=true;
    for(int i=1;i<n;i++){
        int minn=INF,point=-1;
        for(int j=1; j<=n; j++){
            if(!S[j]&&minn>dis[s][j]){
                minn=dis[s][j];
                point=j;
            }
        }
        S[point]=true;
        for(int j=1;j<=n;j++){
            if(!S[j]&&eee[point][j]<INF&&dis[s][j]>eee[point][j]+dis[s][point]){
                dis[s][j]=eee[point][j]+dis[s][point];
                path[j]=point;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(i==s) continue;
        int shortest[maxn],num=0,temp=i;
        shortest[++num]=i;
        while(temp!=s){
            temp=path[temp];
            shortest[++num]=temp;
        }
        for(int j=num;j>0;j--) {
        	ans[shortest[num]][shortest[1]]+=b[shortest[j]]*(num-j);
//            if(j>1) cout<<shortest[j]<<"->";
//            else cout<<shortest[j]<<endl;
		}
//		cout<<"done"<<endl;
    }
}
bool vis[maxn];
void Dijk(int s){
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++) diss[s][i]=INT_MAX;
	diss[s][s]=0;
	int u;
	priority_queue<pri> q;
	q.push((pri{0,s}));
	while(!q.empty()){
		pri temp=q.top();
		q.pop();
		u=temp.id;
		if(!vis[u]){
			vis[u]=1;
			for(int i=head[u];i;i=edge[i].nxt){
				int v=edge[i].to;
				if(diss[s][v]>diss[s][u]+edge[i].w){
					diss[s][v]=diss[s][u]+edge[i].w;
					if(!vis[v]){
						q.push((pri{diss[s][v],v}));
					}
				}
			}
		}
	}
}
int anss[maxn];
vector<int> tree[maxn];
void dfs(int nx,int las){
	for(int i=1;i<=n;i++){
		if(edge[i].to!=las){
			tree[nx].push_back(edge[i].to);
		}
	}
}
void addd(int A,int B){
	eee[A][B]=1;
}
int main(){
	scanf("%d",&n);
	for(int i=2;i<=n;i++) scanf("%d",&f[i]);
	for(int i=2;i<=n;i++) scanf("%d",&A),add(i,f[i],A),add(f[i],i,A);
	for(int i=2;i<=n;i++) scanf("%d",&g[i]),addd(i,g[i]),addd(g[i],i);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	for(int i=1;i<=n;i++) Dijk(i);
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) eee[i][j]=0;
			else if(eee[i][j]==0) eee[i][j]=INF;
		}
	}
	for(int i=1;i<=n;i++){
		Dijkstra(i);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++){
		int maxx=-1e9;
		for(auto j:tree[i]){
			maxx=max(maxx,diss[i][j]+ans[i][j]);
		}
		cout<<maxx<<" ";
	}
	return 0;
}
