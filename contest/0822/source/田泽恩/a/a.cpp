#include <bits/stdc++.h>
using namespace std;
long long n,m,p,dp[10086][10086],s[10086][10086],ans;
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	cin>>n>>m>>p;
	if(n==1){
		cout<<m*(m+1)/2%p;
		return 0;
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			for(int k=j;k<=m;++k){
				if(i==1) dp[j][k]=1;
				else dp[j][k]=0;
				dp[j][k]=(dp[j][k]+s[k][m]-s[k][j-1]+p)%p;
			}
		}
		for(int j=1;j<=m;++j){
			for(int k=1;k<=m;++k){
				s[j][k]=s[j-1][k]+s[j][k-1]-s[j-1][k-1]+dp[j][k];
				s[j][k]=(s[j][k]%p+p)%p;
			}
		}
	}
	for(int i=1;i<=m;++i){
		for(int j=i;j<=m;++j){
			ans=((ans+dp[i][j])%p+p)%p;
		}
	}
	cout<<ans;
	return 0;
}
