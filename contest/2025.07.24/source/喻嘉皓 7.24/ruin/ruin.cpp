#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int N=610;
int n;
int cnt[N];
bool vis[N];
int tmp[2*N],res[2*N];
int a[N];
int ans;
bool check(){
	for(int i=1;i<=2*n;i++) res[i]=tmp[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) vis[j]=0;
		for(int j=2*n;j>=1;j--){
			if(res[j]==0) continue;
			if(vis[res[j]]) res[j]--;
			else vis[res[j]]=1;
		}
	}
	int tot=0;
	for(int i=1;i<=2*n;i++){
		if(res[i]){
			tot++;
			if(i!=a[tot]) return false;
		}
	}
	return true;
}
void dfs(int now){
	if(now>2*n){
		ans+=check();	
		return;
	}
	for(int i=1;i<=n;i++){
		if(cnt[i]==2) continue;
		cnt[i]++; tmp[now]=i;
		dfs(now+1);
		cnt[i]--; tmp[now]=0;
	}
}
int main(){
	freopen("ruin.in","r",stdin);
	freopen("ruin.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1);
	cout<<ans;
	return 0;
}

