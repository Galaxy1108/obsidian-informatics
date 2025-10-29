#include <bits/stdc++.h>
using namespace std;
int n,a[10];
int ans;
unordered_map<int,int> dp;
int count(int cnt,int now){
	int res=0;
	for(int i=1;i<=n;++i) res=res*11+a[i];
	return now?res*11+cnt:-(res*11+cnt);
}
bool dfs(int now,int cnt){
	if(~dp[count(cnt,now)]) return dp[count(cnt,now)];
	//for(int i=1;i<=n;++i) cout<<a[i]<<'_';
	//cout<<cnt<<'\n';
	bool res=!now;
	for(int i=1;i<=n;++i){
		for(int j=cnt;j<=a[i];j+=cnt){
			a[i]-=j;
			if(now) res|=dfs(now^1,j);
			else res&=dfs(now^1,j);
			a[i]+=j;
		}
	}
	return dp[count(cnt,now)]=res;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n;
	for(int i=-1919809;i<1919810;++i) dp[i]=-1;
	if(n<=5){
		for(int i=1;i<=n;++i) cin>>a[i];
		for(int i=1;i<=n;++i){
			for(int j=1;j<=a[i];++j){
				a[i]-=j;
				if(dfs(0,j)) ans++;
				a[i]+=j;
			}
		}
		cout<<ans;
	}
	else{
		for(int i=1;i<=n;++i) cin>>a[i];
		cout<<(n&1);
	}
	return 0;
}
