#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2005;
int w[maxn][maxn],dis[maxn],n,vis[maxn],W[maxn][maxn],qsy[maxn];
void dijk(int s,int d){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			W[i][j]=min(qsy[j]*2-d,w[i][j]);
		}
	}
	for(int i=1;i<=n;i++)dis[i]=1e18;
	dis[s]=0;
	for(int i=1;i<=n;i++){
		int pos=-1;
		for(int j=1;j<=n;j++)if(!vis[j]&&(pos==-1||dis[j]<dis[pos]))pos=j;
		vis[pos]=1;
		for(int j=1;j<=n;j++)if(!vis[j])dis[j]=min(dis[j],dis[pos]+W[pos][j]-d);
	}
}
signed main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;int mn=1e9+1,pu,pv;
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++){
		cin>>w[i][j],w[j][i]=w[i][j];
		if(w[i][j]<mn)pu=i,pv=j,mn=w[i][j];
		W[i][j]=W[j][i]=1e9+1;
	}
	for(int i=1;i<=n;i++){
		qsy[i]=1e9+1;
		for(int j=1;j<=n;j++)if(j!=i)qsy[i]=min(w[i][j],qsy[i]);
	}
	dijk(pu,mn);
	for(int i=1;i<=n;i++){
		cout<<mn*(n-1)+dis[i]<<endl;
	}
	return 0;
}