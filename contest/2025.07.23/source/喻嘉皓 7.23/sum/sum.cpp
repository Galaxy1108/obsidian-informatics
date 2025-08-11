#include<bits/stdc++.h>
#define ll long long
#define INF INT_MAX
using namespace std;
int n,m,K,mod;
int mih[110],miz[110];
int c[110][110];
ll ans;
int get(){
	ll sum=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			sum=(sum*min(mih[i],miz[j]))%mod;
		}
	}
	return sum;
}
void dfs(int x,int y){
	if(x>n){
		ans=(ans+get())%mod;	
		return;
	}
	if(y>m){
		dfs(x+1,1);
		return;
	}
	for(int i=1;i<=K;i++){
		int tmph=mih[x],tmpz=miz[y];
		mih[x]=min(mih[x],i); miz[y]=min(miz[y],i);
		c[x][y]=i;
		dfs(x,y+1);
		mih[x]=tmph; miz[y]=tmpz;
	}
}
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m>>K>>mod;
	for(int i=1;i<=max(n,m);i++){
		mih[i]=miz[i]=INF;
	}
	dfs(1,1);
	cout<<ans;
	return 0;
}

