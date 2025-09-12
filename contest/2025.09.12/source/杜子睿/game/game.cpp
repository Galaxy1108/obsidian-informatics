#include<bits/stdc++.h>
#define zyx std
#define wqm long long
wqm n,m,t,ans,lmf[200005];
bool cmp(wqm x,wqm y){
	return x>y;
}
int main(){
	zyx::ios::sync_with_stdio(0);
	zyx::cin.tie(0);
	zyx::cout.tie(0);
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	zyx::cin>>t;
	while(t--){
		zyx::cin>>n>>m;
		wqm u,v,w;
		memset(lmf,0,sizeof lmf);
		for(wqm i=0;i<m;i++){
			zyx::cin>>u>>v>>w;
			lmf[v]+=w;	
		}
		ans=lmf[u];
		lmf[u]=0;
		zyx::sort(lmf+1,lmf+1+n,cmp);
		for(int i=2;i<=n;i+=2)
			ans+=lmf[i];
		zyx::cout<<ans<<zyx::endl;
	}
	return 0;
}

