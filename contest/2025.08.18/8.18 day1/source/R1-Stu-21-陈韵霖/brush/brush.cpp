#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,u[10005];
ll dp[10005][105];
bool o[10005][105];
ll dfs(int wi,int le){
	if(wi>n) return 0;
	if(o[wi][le]) return dp[wi][le];
	o[wi][le]=1;
	for(int i=wi-m+le+1;i<=wi;++i){
		dp[wi][le]=min(dp[wi][le],dfs(wi+le,i-(wi-m)-le)+u[i]);
	}
	return dp[wi][le];
}
int main(){
	freopen("brush.in","r",stdin);
	freopen("brush.out","w",stdout);
	memset(dp,0x5f,sizeof(dp));
	scanf("%d%d",&n,&m);
	if(n<m) {cout<<0;return 0;}
	for(int i=1;i<=n;++i) scanf("%d",&u[i]);
	ll ans=0;
	for(int i=1;i<m;++i) {
		if(i==1)ans=dfs(m,i)+u[i];
		else ans=min(ans,dfs(m,i)+u[i]);
	}
	cout<<ans;
	return 0;
}
