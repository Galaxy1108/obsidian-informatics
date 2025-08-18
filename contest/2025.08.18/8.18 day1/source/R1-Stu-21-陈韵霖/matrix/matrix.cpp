#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,ka;
int k[105][2],su[105][2],sa[105];
ll dp[105][105][11];
bool o[105][105][11];
ll dfs(int ai,int bi,int kk){
	if(kk==0){
		return 0;
	}
	if(o[ai][bi][kk]) return dp[ai][bi][kk];
	o[ai][bi][kk]=1;
	dp[ai][bi][kk]=-1e7;
	int mi=su[ai][0];
	for(int i=ai+1;i<=n;++i){
		dp[ai][bi][kk]=max(dp[ai][bi][kk],dfs(i,bi,kk-1)+su[i][0]-mi);
		mi=min(mi,su[i][0]);
	}
	if(m>1){
		mi=su[bi][1];
		for(int i=bi+1;i<=n;++i){
			dp[ai][bi][kk]=max(dp[ai][bi][kk],dfs(ai,i,kk-1)+su[i][1]-mi);
			mi=min(mi,su[i][1]);
		}
		mi=sa[max(ai,bi)];
		for(int i=max(ai,bi)+1;i<=n;++i){
			dp[ai][bi][kk]=max(dp[ai][bi][kk],dfs(i,i,kk-1)+sa[i]-mi);
			mi=min(mi,sa[i]);
		}
	}
	return dp[ai][bi][kk];
}
int main(){
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	scanf("%d%d%d",&n,&m,&ka);
	for(int i=1;i<=n;++i){
		for(int j=0;j<m;++j){
			scanf("%d",&k[i][j]);
		}
	}
	for(int r=0;r<m;++r){
		for(int i=1;i<=n;++i){
			su[i][r]=su[i-1][r]+k[i][r];	
		}
	}
	for(int i=1;i<=n;++i) sa[i]=sa[i-1]+k[i][0]+k[i][1];
	cout<<dfs(0,0,ka);
	return 0;
}
