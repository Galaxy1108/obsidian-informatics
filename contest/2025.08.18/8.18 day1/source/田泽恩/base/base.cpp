#include <bits/stdc++.h>
using namespace std;
long long n,a[2][2145],sum[3][2145],lft[2145],rit[2145],ans;
int main(){
	freopen("base.in","r",stdin);
	freopen("base.out","w",stdout);
	ans=-0x3f3f3f3f3f3f3f3f;
	cin>>n;
	for(int i=0;i<2;++i){
		for(int j=1;j<=n;++j){
			cin>>a[i][j];
			sum[i][j]=sum[i][j-1]+a[i][j];
		}
	}
	for(int i=1;i<=n;++i) sum[2][i]=sum[0][i]+sum[1][i];
	memset(lft,128,sizeof(lft));
	memset(rit,128,sizeof(rit));
	for(int i=2;i<n;++i){
		for(int j=1;j<i;++j){
			lft[i]=max(lft[i],sum[2][i-1]-sum[2][j-1]);
		}
	}
	for(int i=n-1;i>1;--i){
		for(int j=n;j>i;--j){
			rit[i]=max(rit[i],sum[2][j]-sum[2][i]);
		}
	}
	for(int i=2;i<n;++i){
		for(int j=i;j<n;++j){
			ans=max(ans,sum[1][j]-sum[1][i-1]+lft[i]+rit[j]);
		}
	}
	cout<<ans;
	return 0;
}
