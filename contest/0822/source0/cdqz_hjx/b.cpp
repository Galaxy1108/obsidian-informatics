#include<bits/stdc++.h>
#define int long long
using namespace std;
int mp[9][9],n,x,ans=1e17,vis[9],res;
void dfs(int nw,int u,int mn){
	if(nw==n){
		ans=min(ans,res);
		return;
	}
	for(int i=1;i<=n;++i){
		if(i==u||vis[i]) continue;
		int g=mn;
		mn=min(mn,mp[u][i]);
		res+=mn;
		vis[i]=1;
		dfs(nw+1,i,mn);
		vis[i]=0;
		res-=mn;
		mn=g;
	}
}
signed main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			cin>>x;
			mp[i][j]=x;
			mp[j][i]=x;
		}
	}
	for(int i=1;i<=n;++i){
		ans=1e17;res=0;
		dfs(1,i,1e17);
		cout<<ans<<'\n';
	}
	return 0;
}



