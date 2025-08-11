#include<iostream>
#include<cstring>
using namespace std;
long long dp[1000086],h,w,e[1000086],s[1000086];
int main(){
	freopen("kyoto.in","r",stdin);
	freopen("kyoto.out","w",stdout);
	cin >> h >> w;
	memset(dp,0x3f,sizeof dp);
	for(int i=1;i<=h;i++)scanf("%d",&e[i]);
	for(int i=1;i<=w;i++)scanf("%d",&s[i]);
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			dp[j]=min(dp[j-1]+e[i],dp[j]+s[j]);
			if(i==1 and j==1)dp[1]=0;
		}
	}
	cout << dp[w];
	return 0;
}
