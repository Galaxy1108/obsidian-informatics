#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2005;
const int inf=1e9;
int n,w[N][N],dis[2][N],vis[N];
void dij(int x,int type){
	memset(dis[type],-1,sizeof dis[type]);
	memset(vis,0,sizeof vis);
	dis[type][x]=0;
	for(int i=1;i<=n;i++){
		int u=0;
		for(int j=1;j<=n;j++){
			if(vis[j] || dis[type][j]==-1) continue;
			if(!u || dis[type][j]<dis[type][u]) u=j;
		}
		vis[u]=1;
		for(int j=1;j<=n;j++){
			if(dis[type][j]==-1 || dis[type][j]>dis[type][u]+w[j][u]){
				dis[type][j]=dis[type][u]+w[j][u];
			} 
		}
	}
}
signed main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	int x=0,y=0,val=0; 
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			cin>>w[i][j];
			w[j][i]=w[i][j];
			if(!x || w[i][j]<w[x][y]) x=i,y=j;
		}
	}
	val=w[x][y];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j) w[i][j]-=val;
		}
	}
	for(int i=1;i<=n;i++){
		int mi=inf;
		for(int j=1;j<=n;j++){
			if(i!=j) mi=min(mi,w[i][j]); 
		}
		for(int j=1;j<=n;j++){
			w[i][j]=min(w[i][j],mi*2);
		}
	}
	dij(x,0),dij(y,1);
	for(int i=1;i<=n;i++){
		cout<<min(dis[0][i],dis[1][i])+(n-1)*val<<"\n"; 
	} 
} 
