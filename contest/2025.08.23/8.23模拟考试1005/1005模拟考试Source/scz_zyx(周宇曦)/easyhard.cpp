#include<bits/stdc++.h>
using namespace std;
inline void file(string str) {
    freopen((str + ".in").c_str(), "r", stdin);
    freopen((str + ".out").c_str(), "w", stdout);
}
int dp[3010][3010],m,mod;
int work(int n){
	memset(dp,0,sizeof(dp));
	for(int i=0;i<=n;i++) dp[0][i]=1;
	for(int i=0;i<m;i++)
	for(int j=0;j<=n;j++){
		if(j) dp[i+1][j]=(dp[i+1][j]+dp[i][j])%mod;
		if(n-j) dp[i+1][j]=(dp[i+1][j]+dp[i][j])%mod;
		if(j) dp[i+1][j-1]=(dp[i+1][j-1]+dp[i][j])%mod;
		if(n-j) dp[i+1][j+1]=(dp[i+1][j+1]+dp[i][j])%mod;
	}
	int ans=0;
	for(int i=0;i<=n;i++)
	ans=(ans+dp[m][i])%mod;
	return ans;
}
int main(){
	file("easyhard");
	int n;
	scanf("%d%d%d",&n,&m,&mod);
	printf("%d",(work(n)-work(n-1)+mod)%mod);
	return 0;
}
