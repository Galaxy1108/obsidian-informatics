#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
const int mod=998244353;
const int N=5010;
int n,m;
int L[N],R[N];
struct Path{
	int u,v,w;
}p[N];
int qpow(int d,int z){
	int res=1,now=d;
	while(z){
		if(z&1) res=res*now%mod;
		now=now*now%mod; z>>=1;
	}
	return res;
}
vector<int> g[N];
int ans[N][N];
bool vis[N];
int Inv(int num){
	return qpow(num,mod-2);
}
int fa[N];
void solve(){
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<=n;i++){
		g[fa[i]].pb(i);
		g[i].pb(fa[i]);
	}
	for(int i=1;i<=m;i++){
		int u=p[i].u,v=p[i].v,w=p[i].w;
		for(int i=1;i<=n;i++) vis[i]=0;
		while(u){
			vis[u]=1;
			u=fa[u];
		} 
		int lca;
		while(v){
			if(vis[v]){
				lca=v;
				break;
			}
			v=fa[v];
		}
		while(u!=lca){
			ans[u][fa[u]]+=w;
			ans[u][fa[u]]%=mod;
		}
		while(v!=lca){
			ans[v][fa[v]]+=w;
			ans[v][fa[v]]%=mod;
		}
	}
}
void dfs(int now){
	if(now>n){
		solve();
		return;
	}
	for(int i=L[now];i<=R[now];i++){
		fa[i]=i;
		dfs(now+1);
		fa[i]=0;
	}
}
signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<n;i++){
		cin>>L[i]>>R[i];
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>p[i].u>>p[i].v>>p[i].w;
	}
	dfs(1);
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=L[i];j<=R[i];j++){
			sum+=ans[i][j];
		}
		sum=sum*Inv(R[i]-L[i]+1)%mod;
		cout<<sum<<' ';
	}
	return 0;
}

