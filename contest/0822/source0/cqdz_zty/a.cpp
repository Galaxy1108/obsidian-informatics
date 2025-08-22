#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,mod;
ll f[2505][2505],ans=0;
ll sum,sl[2505],sr[2505];
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	cin>>n>>m>>mod;
	if(n==1){
		cout<<(m+1)*m/2%mod;
		return 0;
	}
	if(m==1){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=m;i++){
		for(int j=i;j<=m;j++){
			f[i][j]=1;
		}
	}
	for(int i=1;i<=m;i++){
		sl[i]=i;
		sl[i]=(i+sl[i-1])%mod;
	}
	for(int i=m;i>=1;i--){
		sr[i]=m-i+1;
		sr[i]=(m-i+1+sr[i+1])%mod;
	}
	sum=m*(m+1)/2%mod;
	for(int i=2;i<=n;i++){
		//cout<<sum<<'\n';
		for(int j=1;j<=m;j++){
			//cout<<f[j][j]<<' ';
			for(int k=j;k<=m;k++){
				f[j][k]=(sum-sl[j-1]-sr[k+1]+mod*2)%mod;
			}
		}
		sum=0;for(int i=1;i<=m;i++) sl[i]=sr[i]=0;
		for(int j=1;j<=m;j++){
			for(int k=j;k<=m;k++){
				sum=(sum+f[j][k])%mod;
				sl[k]=(sl[k]+f[j][k])%mod;
				sr[j]=(sr[j]+f[j][k])%mod;
			}
		}
		
		for(int j=1;j<=m;j++){
			sl[j]=(sl[j]+sl[j-1])%mod;
		}
		for(int j=m;j>=1;j--){
			sr[j]=(sr[j]+sr[j+1])%mod;
		}
	}
	cout<<sum%mod;
	return 0;
}
/*
3 2 100000007
114 514 998244353

*/
