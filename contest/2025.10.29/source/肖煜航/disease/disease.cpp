#include <bits/stdc++.h>
#define pb emplace_back
using namespace std;
const int N=305;
int n,m;
vector<int>e[N],a[N];
int dep[N],f[N];
bitset<N>vis;
int ans=N;
void dfs(int u,int fa){
	f[u]=fa;
	dep[u]=dep[fa]+1; 
	a[dep[u]].pb(u);
	for(auto v:e[u]){
		if(v==fa)
			continue;
		dfs(v,u);
	}
}
void solve(int nowdep,int sum){
	if(sum>=ans)
		return;
	if(!a[nowdep].size())
		return void(ans=min(ans,sum)-1);
	int cnt=0;
	for(auto v:a[nowdep]){
		if(vis[f[v]])
			vis[v]=1;
		else
			cnt++;
	}
	if(!cnt)
		ans=min(ans,sum);
	for(auto v:a[nowdep])
		if(!vis[v]){
			vis[v]=1;
			solve(nowdep+1,sum+cnt-1);
			vis[v]=0;
		}
	for(auto v:a[nowdep])
		if(vis[v])
			vis[v]=0;
}
int main(){
	freopen("disease.in","r",stdin);
	freopen("disease.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1,u,v;i<n;i++)
		cin>>u>>v,e[u].pb(v),e[v].pb(u);
	dfs(1,0);
	vis.reset();
	solve(2,1);
	cout<<ans;
	return 0;
}
