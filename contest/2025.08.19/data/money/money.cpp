#include<bits/stdc++.h>
using namespace std;
int n,C,w[3001],s[3001];
double c[3001],d[3001],dp[3001][2];
char ns[1001],ng[1001];
signed main(){
for(int ii=0;ii<20;ii++){
	memset(s,0,sizeof(s));
//	ans=-inf;
	memset(dp,0,sizeof(dp));
//	jfl=0;
	sprintf(ns,"money%d.in",ii);
		freopen(ns,"r",stdin);
		sprintf(ng,"money%d.out",ii);
		freopen(ng,"w",stdout);
	cin>>n>>C;
	for(int i=1;i<=n;i++)cin>>w[i]>>c[i]>>d[i],s[i]=s[i-1]+w[i];
	for(int i=1;i<=n;i++){
		dp[i][0]=max(dp[i][0],dp[i-1][0]+w[i]);
		dp[i][1]=max(dp[i][1],dp[i-1][1]+w[i]*c[i]);
		for(int j=1;j<i;j++)dp[i][0]=max(dp[i][0],dp[j][1]*d[i]-C+s[i]-s[j]);
		for(int j=1;j<i;j++)dp[i][1]=max(dp[i][1],(dp[j][0]+s[i]-s[j])*c[i]);
	}
	printf("%.4f\n",dp[n][0]);
}
	return 0;
}
