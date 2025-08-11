#include<bits/stdc++.h>
#define ll long long
#define int long long
#define add(x,y) x=(x+y%mod)%mod
using namespace std;
const int mod=998244353;
const int N=5010;
int n,m;
int s[N];
int f[N][N];
int dp[N];
int Sum[N];
int fac[N],inv[N];
void init(){
	fac[0]=inv[0]=1;
	for(int i=1;i<=n;i++){
		fac[i]=fac[i-1]*i%mod;
	}
	
}
signed main(){
	freopen("mex.in","r",stdin);
	freopen("mex.out","w",stdout);
	cin>>n>>m;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>s[i];	sum+=s[i];
	}
	for(int i=n;i>=1;i--) Sum[i]=Sum[i+1]+s[i];
	if(sum-1>m){
		cout<<0;
		return 0;
	}
	f[0][0]=1;
//	for(int i=1;i<=n;i++){
//		for(int j=0;j<=n;j++){
//			if(s[i]&&j) add(f[i][j],f[i-1][j-1]);
//			else if(!s[i]) add(f[i][j],f[i-1][j]*m);
//		}
//	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(s[i]) f[i][j]=f[i-1][j-1];
			else{
				add(f[i][j],f[i-1][j]*j);
				if(m+1-Sum[i]-(j-1)>0) add(f[i][j],f[i-1][j-1]*(m-j+1));
			}
		}
	}
//	dp[0]=1;
//	for(int i=1;i<=n;i++){
//		if(s[i]) dp[i]=dp[i-1];
//		else dp[i]=dp[i-1]*m%mod;
//	}
	ll ans=0;
	for(int i=sum;i<=n;i++){
		add(ans,f[n][i]);
	}
	cout<<ans;
//	cout<<dp[n];
	return 0;
}

