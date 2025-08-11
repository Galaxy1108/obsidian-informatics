#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int n,m;
int a[5010];
long long ans;
long long f[5010][5010];
int main()
{
	freopen("mex.in","r",stdin);
	freopen("mex.out","w",stdout);
	scanf("%d%d",&n,&m);++m;
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	f[0][0]=1;
	for(int i=1;i<=n;++i){
		if(a[i]){
			for(int j=1;j<=n;++j) f[i][j]=(f[i][j]+f[i-1][j-1])%mod;
		}
		else{
			for(int j=1;j<=n;++j) f[i][j]=(f[i][j]+f[i-1][j-1]*(m-j))%mod;
			for(int j=1;j<=n;++j) f[i][j]=(f[i][j]+f[i-1][j]*j)%mod;
		}
	}
	for(int i=0;i<=min(n,m);++i) ans=(ans+f[n][i])%mod;
	printf("%lld\n",ans);
	return 0;
}