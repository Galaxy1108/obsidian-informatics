#include<bits/stdc++.h>
#define inf 999999999
using namespace std;
int n,w[10001],u[10001],t[10001],dp[10001],jfl,mx[10001];
int v[51]={0,100,100,97,96,95,90,85,80,82,78,75,70,65,55,50,15,12,10,8,5,2};
char ns[1001],ng[1001];
signed main(){
for(int ii=10;ii<20;ii++){
	memset(dp,0,sizeof(dp));
	memset(mx,0,sizeof(mx));
	jfl=0;
	sprintf(ns,"sniper%d.in",ii);
		freopen(ns,"r",stdin);
		sprintf(ng,"sniper%d.out",ii);
		freopen(ng,"w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>w[i]>>u[i]>>t[i];
	for(int i=1;i<=n;i++){
		dp[i]=-inf;
		for(int j=i-1;j>=1;j--){
			if(abs(u[i]-u[j])<=2*(t[i]-t[j]-1)&&t[i]>t[j]+1)dp[i]=max(dp[i],dp[j]);
			if(w[j]==15)break;
			if(t[i]-t[j]>=12){
				dp[i]=max(dp[i],mx[j]);
				break;
			}
		}
		dp[i]+=v[w[i]];
		if(!jfl)dp[i]=max(dp[i],v[w[i]]);
		if(w[i]==15)jfl=1,mx[i]=dp[i];
		else mx[i]=max(mx[i-1],dp[i]);
	}
	cout<<mx[n]<<endl;
}
	return 0;
}
