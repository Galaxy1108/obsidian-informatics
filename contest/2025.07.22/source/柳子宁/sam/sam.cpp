#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
long long n,Ans;
struct Matrix{
	long long a[10][10];
	Matrix operator *(const Matrix &x) const{
		Matrix ans;memset(ans.a,0,sizeof(ans.a));
		for(int i=0;i<10;++i){
			for(int j=0;j<10;++j){
				for(int k=0;k<10;++k){
					ans.a[i][j]=(ans.a[i][j]+a[i][k]*x.a[k][j])%mod;
				}
			}
		}
		return ans;
	}
}ans,a;
Matrix fastpow(Matrix x,long long y){
	Matrix ans;
	memset(ans.a,0,sizeof(ans.a));
	for(int i=0;i<10;++i) ans.a[i][i]=1;
	while(y){
		if(y&1) ans=(ans*x);
		x=(x*x);
		y>>=1;
	}
	return ans;
}
int main()
{
	freopen("sam.in","r",stdin);
	freopen("sam.out","w",stdout);
	scanf("%lld",&n);
	for(int i=0;i<10;++i){
		for(int k=max(0,i-2);k<=min(9,i+2);++k){
			a.a[i][k]=1;
		}
	}
	ans=fastpow(a,n-1);
	for(int i=0;i<10;++i){
		for(int j=1;j<10;++j){
			Ans=(Ans+ans.a[i][j])%mod;
		}
	}
	printf("%lld\n",Ans);
	return 0;
}