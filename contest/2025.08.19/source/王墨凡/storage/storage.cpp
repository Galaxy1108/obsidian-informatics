#include<iostream>
#include<cstring>
using namespace std;
unsigned long long dp[10086],dis[10086],x[10086],p[10086],c[10086],n,num[10086];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("storage.in","r",stdin);
	freopen("storage.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)dp[i]=1e18;
	for(int i=1;i<=n;i++){
		cin >> x[i] >> p[i] >> c[i];
		num[i]=p[i]+num[i-1];
		dis[i]=dis[i-1]+num[i-1]*(x[i]-x[i-1]);
	}
	dp[0]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++){
			dp[i]=min(dp[i],dp[j]+dis[i]-dis[j]-num[j]*(x[i]-x[j]));
		}
		dp[i]+=c[i];
	}
	cout << dp[n];
}
/*
*/
