#include <bits/stdc++.h>
using namespace std;
int n,w[8080],u[8080],t[8080],dp[8080],W[8080],wei[22],lst[8080],ans;
bool flag;
void init(){
	wei[1]=wei[2]=100;
	wei[3]=97;
	wei[4]=96;
	wei[5]=95;
	wei[6]=90;
	wei[7]=85;
	wei[8]=80;
	wei[9]=82;
	wei[10]=78;
	wei[11]=75;
	wei[12]=70;
	wei[13]=65;
	wei[14]=55;
	wei[15]=50;
	wei[16]=15;
	wei[17]=12;
	wei[18]=10;
	wei[19]=8;
	wei[20]=5;
	wei[21]=2;
}
int main(){
	freopen("sniper.in","r",stdin);
	freopen("sniper.out","w",stdout);
	cin>>n;
	init();
	for(int i=1;i<=n;++i){
		cin>>w[i]>>u[i]>>t[i];
		lst[i]=lst[i-1];
		if(w[i-1]==15) lst[i]=i-1;
		W[i]=wei[w[i]];
	}
	for(int i=1;i<=n;++i){
		dp[i]=W[i];
		for(int j=lst[i];t[j]+1<t[i];++j){
			if(abs(u[i]-u[j])<=2*(t[i]-t[j]-1)||j==0) dp[i]=max(dp[i],dp[j]+W[i]);
		}
	}
	if(w[n]==15){
		cout<<dp[n];
		return 0;
	}
	for(int i=lst[n];i<=n;++i) ans=max(ans,dp[i]);
	cout<<ans;
	return 0;
} 
