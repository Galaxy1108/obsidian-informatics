#include <bits/stdc++.h>
using namespace std;
long long h,w,a[1145],b[1145],dp[1145][1145];
int main(){
	freopen("kyoto.in","r",stdin);
	freopen("kyoto.out","w",stdout);
	memset(dp,0x3f,sizeof(dp));
	cin>>h>>w;
	for(int i=1;i<=h;++i) cin>>a[i];
	for(int i=1;i<=w;++i) cin>>b[i];
	dp[1][1]=0;
	for(int i=2;i<=h;++i) dp[i][1]=(i-1)*b[1];
	for(int i=2;i<=w;++i) dp[1][i]=(i-1)*a[1];
	for(int i=2;i<=h;++i){
		for(int j=2;j<=w;++j){
			dp[i][j]=min(dp[i][j-1]+a[i],dp[i-1][j]+b[j]);
		}
	}
	cout<<dp[h][w];
	return 0;
}
