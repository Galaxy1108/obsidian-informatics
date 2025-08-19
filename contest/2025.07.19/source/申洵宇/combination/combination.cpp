#include <bits/stdc++.h>
using namespace std;
#define M 1005
long long n,x,MOD,m,a[M];
namespace sub1{
	long long C[1005][1005];
	inline void init(int mx){
		for(int i=0;i<=mx;i++){
			for(int j=0;j<=i;j++){
				if(j==0||j==i)C[i][j]=1;
				else C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
			}
		}
	}
	inline long long f(long long x){
		long long res=0,p=1;
		for(int i=0;i<=m;i++){
			res=(res+a[i]*p%MOD)%MOD;
			p=p*x%MOD;
		}
		return res;
	}
	inline void solve(){
		init(n);
		long long res=0,p=1;
		for(int k=0;k<=n;k++){
			res=(res+f(k)*p%MOD*C[n][k]%MOD)%MOD;
			p=p*x%MOD;
		}
		printf("%lld",res);
	}
}
namespace sub2{
	long long fac[100005],invfac[100005];
	inline long long mpow(long long b,long long p){
		long long res=1;
		while(p){
			if(p&1)res=res*b%MOD;
			p>>=1;
			b=b*b%MOD;
		}
		return res;
	}
	inline void init(){
		fac[0]=1;
		for(register long long i=1;i<=n;i++){
			fac[i]=fac[i-1]*i%MOD;
		}
		invfac[n]=mpow(fac[n],MOD-2);
		for(long long i=n-1;i>=0;i--){
			invfac[i]=invfac[i+1]*(i+1ll)%MOD;
		}
	}
	inline long long C(long long n,long long m){
		return fac[n]*invfac[m]%MOD*invfac[n-m]%MOD;
	}
	inline void solve(){
		init();
		long long res=0,p=1;
		for(int k=0;k<=n;k++){
			res=(res+p*C(n,k)%MOD)%MOD;
			p=p*x%MOD;
		}
		printf("%lld",res*a[0]%MOD);
	}
}
int main(){
	freopen("combination.in","r",stdin);
	freopen("combination.out","w",stdout);
	scanf("%lld%lld%lld%lld",&n,&x,&MOD,&m);
	for(int i=0;i<=m;i++){
		scanf("%lld",&a[i]);
	}
	if(n<=1000&&m<=1000){
		sub1::solve();
	}
	else if(m==0){
		sub2::solve();
	}
	else{
		printf("0");
	}
	return 0;
}
