#include <bits/stdc++.h>
using namespace std;
string s[44];
int n,vis[44],flw[88];
void dfs(int now){
	if(now==2*n+1){
		for(int i=1;i<=2*n;++i) cout<<s[flw[i]]<<'\n';
		exit(0);
	}
	if(flw[now]){
		dfs(now+1);
		return;
	}
	for(int i=n;i;--i){
		if(!vis[i]&&now+i+1>2*n) return;
		if(!vis[i]){
			bool flag=true;
			for(int j=now+i+1;j<=2*n;++j) flag&=flw[j];
			if(flag) return;
		}
	}
	for(int i=n;i;--i){
		if(!vis[i]&&!flw[now+i+1]){
			flw[now]=flw[now+i+1]=i;
			vis[i]=1;
			dfs(now+1);
			flw[now]=flw[now+i+1]=0;
			vis[i]=0;
		}
	}
}
int main(){
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>s[i];
	dfs(1);
	return 0;
}
