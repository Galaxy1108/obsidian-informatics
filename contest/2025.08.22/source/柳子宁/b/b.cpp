#include<bits/stdc++.h>
#define inf 1000000000000000000
using namespace std;
int n,mn,x,y;
int w[2010][2010],tag[2010];
long long ans[2010],dis[2010];
int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d",&n);
	mn=1000000010;
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			scanf("%d",&w[i][j]);
			w[j][i]=w[i][j];
			if(w[i][j]<mn) mn=w[i][j],x=i,y=j;
		}
	}

	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			w[i][j]-=mn;
			w[j][i]-=mn;
		}
	}

	for(int i=0;i<=n;++i) dis[i]=inf;
	dis[x]=dis[y]=0;
	for(int i=1;i<=n;++i){
		if(i==x||i==y) continue;
		dis[i]=min(w[x][i],w[y][i]);
		for(int j=1;j<=n;++j){
			if(i==j) continue;
			dis[i]=min(dis[i],2ll*w[j][i]);
		}
	}

	for(int k=1;k<=n;++k){
		int p=0;
		for(int j=1;j<=n;++j) if(!tag[j]&&dis[j]<dis[p]) p=j;
		tag[p]=1;
		for(int j=1;j<=n;++j) dis[j]=min(dis[j],dis[p]+w[p][j]);
	}
	
	for(int i=1;i<=n;++i) ans[i]=1ll*mn*(n-1)+dis[i];
	for(int i=1;i<=n;++i) printf("%lld\n",ans[i]);
	return 0;
}
