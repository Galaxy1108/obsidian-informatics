#include<bits/stdc++.h>
using namespace std;
long long n,x,mod,m,N,val,ans;
long long A[5010],a[5010];
long long S[5010][5010],c[5010][5010];
long long fastpow(long long x,int y){
	long long ans=1;
	while(y){
		if(y&1) ans=(ans*x)%mod;
		x=(x*x)%mod;
		y>>=1;
	}
	return ans;
}
long long C(int n,int m){
	if(n<0||m<0||n<m) return 0;
	return c[n][m];
}
void Init(){
	int N=5002;
	S[0][0]=1;c[0][0]=1;
	for(int i=1;i<=N;++i){
		for(int j=1;j<=i;++j){
			S[i][j]=(S[i-1][j]*j+S[i-1][j-1])%mod;
		}
		c[i][0]=c[i][i]=1;
		for(int j=1;j<i;++j) c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
	}
	return;
}
int main()
{
	freopen("combination.in","r",stdin);
	freopen("combination.out","w",stdout);
	scanf("%lld%lld%lld%lld",&n,&x,&mod,&m);
	for(int i=0;i<=m;++i) scanf("%lld",&A[i]);
	Init();
	for(int i=0;i<=m;++i){
		for(int j=0;j<=i;++j){
			a[j]=(a[j]+A[i]*S[i][j])%mod;
		}
	}
	N=1;
	for(int i=0;i<=m;++i){
		if(i) N=(N*(n-i+1))%mod;
		val=N*a[i]%mod;
		val=val*fastpow(x,i)%mod;
		val=val*fastpow(x+1,n-i)%mod; 
		ans=(ans+val)%mod;
	}
	printf("%lld\n",ans);
	return 0;
}
