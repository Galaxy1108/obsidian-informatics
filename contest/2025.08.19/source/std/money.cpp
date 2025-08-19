#include<bits/stdc++.h>
using namespace std;
int n,C,w[3001],s[3001];
double c[3001],d[3001],dp[3001][2];
signed main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>n>>C;
	for(int i=1;i<=n;i++)cin>>w[i]>>c[i]>>d[i],s[i]=s[i-1]+w[i];
	for(int i=1;i<=n;i++){
		dp[i][0]=max(dp[i][0],dp[i-1][0]+w[i]);
		dp[i][1]=max(dp[i][1],dp[i-1][1]+w[i]*c[i]);
		for(int j=1;j<i;j++)dp[i][0]=max(dp[i][0],dp[j][1]*d[i]-C+s[i]-s[j]);
		for(int j=1;j<i;j++)dp[i][1]=max(dp[i][1],(dp[j][0]+s[i]-s[j])*c[i]);
	}
	printf("%.4f\n",dp[n][0]);
	return 0;
}
