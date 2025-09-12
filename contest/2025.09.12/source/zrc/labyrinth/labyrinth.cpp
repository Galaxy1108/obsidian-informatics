#include<bits/stdc++.h>
#define F(i,a,b) for(int i(a),i##i##end(b);i<=i##i##end;++i)
#define R(i,a,b) for(int i(a),i##i##end(b);i>=i##i##end;--i)
#define ll long long
#define File(a) freopen(#a".in","r",stdin);freopen(#a".out","w",stdout)
using namespace std;
const int MAXN=2e5+1;
int n,dp[MAXN],ans;
vector<int>g[MAXN];
void dfs(int now,int fa){
	int v=0;
	dp[now]=0;
	for(int i:g[now]){
		if(i==fa) continue;
		dfs(i,now);
		F(t,0,19) if(((dp[i]&dp[now])>>t)&1) v=max(v,t+1);
		dp[now]|=dp[i];
	}
	while((dp[now]>>v)&1) ++v;
	dp[now]=((dp[now]>>v)|1)<<v;
	ans=max(ans,v);
	return;
}
int main(){
	File(labyrinth);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	for(cin>>T;T;--T){
		ans=0;
		F(i,1,n) g[i].clear();
		cin>>n;
		F(i,1,n-1){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1,0);
		cout<<ans+1<<"\n";
	}
	return 0;
}
