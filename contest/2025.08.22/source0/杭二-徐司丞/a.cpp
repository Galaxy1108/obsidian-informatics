#include<bits/stdc++.h>
using namespace std;
const int N=1e7+7;
int n,m,p,dp[N],dp2[N],ds[N],ds2[N],sum[N];
signed main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>p;
	dp[m]=dp2[1]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			ds[j]=ds2[j]=0;
		for(int j=m;j>=1;j--){
			sum[j]=(sum[j+1]+dp2[j])%p;
		}
		for(int j=1;j<=m;j++){
			ds2[j]=1ll*(dp[m]-dp[j-1])*(m-j+1)%p;
			ds2[j]=((ds2[j]-sum[j+1])%p+p)%p;
		}
		for(int j=1;j<=m;j++){
			sum[j]=(sum[j-1]+dp[j])%p;
		}
		for(int j=1;j<=m;j++){
			ds[j]=1ll*(dp[m]-dp2[j+1])*j%p;
			ds[j]=((ds[j]-sum[j-1])%p+p)%p;
		}
		for(int j=1;j<=m;j++)
			dp[j]=(ds[j]+dp[j-1])%p;
		for(int j=m;j>=1;j--)
			dp2[j]=(ds2[j]+dp2[j+1])%p;
	}
	cout<<(dp[m]%p+p)%p<<"\n";
	return 0;
}
