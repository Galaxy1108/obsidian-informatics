#include<iostream>
#include<cstring>
using namespace std;
long long n,m,a[10086],dp[10086][186];
long long q[10086],t,h;
int main(){
	freopen("brush.in","r",stdin);
	freopen("brush.out","w",stdout);
	memset(dp,0x3f,sizeof dp);
	cin >> n >> m;
	for(int i=1;i<=n;i++)cin >> a[i];
	for(int i=2 ;i<=m;i++){
		for(int j=1;j<i;j++){
			dp[i][j]=a[i]+a[i-j];
		}
	}
	for(int i=m;i<=n;i++){
		for(int j=1;j<m;j++){
			for(int k=1;k<=m-j;k++){
				dp[i][j]=min(dp[i][j],a[i]+dp[i-j][k]);
			}
		}
	}
	long long ans=1e18;
	for(int i=n-m+2;i<=n;i++){
		for(int j=1;j<i-n+m;j++){
			ans=min(ans,dp[i][j]);
		}
	}
	cout << ans; 
	return 0;
} 
