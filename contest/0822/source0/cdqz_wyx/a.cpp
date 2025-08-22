#include<bits/stdc++.h>
using namespace std;
int n,m,mod;
const int M=1e7+5;
int FL[M<<1],FR[M<<1];
int *fl[M],*fr[M];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	cin>>n>>m>>mod;
	for(int i=1;i<=n;i++){
		fl[i]=FL+(i-1)*(m+1);
		fr[i]=FR+(i-1)*(m+1);
	}
	for(int i=1;i<=m;i++)fl[1][i]=(m-i+1);
	for(int i=1;i<=m;i++)fr[1][i]=i;
	int sum;
	for(int i=2;i<=n;i++){
		sum=0;
		for(int j=1;j<=m;j++){
			sum=(sum+fl[i-1][j])%mod;
			fr[i-1][j]=(fr[i-1][j]+fr[i-1][j-1])%mod;
		}
		for(int j=1;j<=m;j++)fr[i-1][j]=(fr[i-1][j]+fr[i-1][j-1])%mod;
		for(int j=m;j>=1;j--)fl[i-1][j]=(fl[i-1][j]+fl[i-1][j+1])%mod;
		for(int j=m;j>=1;j--)fl[i-1][j]=(fl[i-1][j]+fl[i-1][j+1])%mod;
		for(int j=1;j<=m;j++){
			fl[i][j]=(0ll+1ll*(m-j+1)*sum%mod-1ll*(m-j+1)*((fr[i-1][j-1]-fr[i-1][max(0,j-2)]+mod)%mod)%mod+mod-fl[i-1][j+1]+mod)%mod;
			fr[i][j]=(0ll+1ll*j*sum%mod-1ll*j*((fl[i-1][j+1]-fl[i-1][min(j+2,m+1)]+mod)%mod)%mod+mod-fr[i-1][j-1]+mod)%mod;
			// cerr<<i<<" "<<j<<" "<<fl[i][j]<<" "<<fr[i][j]<<'\n';
		}
	}
	sum=0;
	for(int i=1;i<=m;i++)sum=(sum+fl[n][i])%mod;
	cout<<sum;
	return 0;
}