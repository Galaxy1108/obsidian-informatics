#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,w[2010][2010],f[2010],ans,cnt;
void dfs(ll x,ll y){
	if(y==x) return;
	for(int i=1;i<=n;i++){
		if(!f[i]){
			cnt=min(cnt,w[x][i]);
			f[i]=1;
			dfs(i,y);
			f[i]=0; 
		}
	}
	return;
}
int main(){
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n-i;j++){
			scanf("%lld",&w[i][i+j]);
			w[i+j][i]=w[i][i+j];
		}
	}
	for(ll i=1;i<=n;i++){
		ans=0;
		for(ll j=1;j<=n;j++){
			if(j!=i){
				cnt=1e14;
				memset(f,0,sizeof(f));
				f[i]=1;
				dfs(i,j);
				ans+=cnt;	
			}
		}
		printf("%d\n",ans);
	}
}
/*
3
1 2
3
*/
