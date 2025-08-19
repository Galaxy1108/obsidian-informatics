// n^2 40pts
#include <iostream>
#define INF 0x7fffffffffffffff
int n,all[10001][3];
long long dp[10001];
int main(){
	freopen("storage.in","r",stdin);
	freopen("storage.out", "w", stdout);
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);
	std::cin>>n;
	for(int i=1;i<=n;i++) std::cin>>all[i][0]>>all[i][1]>>all[i][2];
	all[0][0]=0,all[0][1]=0,dp[0]=0;
	for(int i=1;i<=n;i++){
		long long dist=0,mn=INF;
		for(int j=i-1;~j;j--){
			if(dist+dp[j]<mn) mn=dist+dp[j];
			dist+=(all[i][0]-all[j][0])*all[j][1];
		}
		dp[i]=mn+all[i][2];
		// std::cout<<mn<<' '<<dp[i]<<'\n';
	}
	std::cout<<dp[n];
}