#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=1e9+7;
ll n;
struct matr{
	ll x[20][20];
};
matr operator * (matr a,matr b){
	matr c;
	for(int i=0;i<=10;i++){
		for(int j=0;j<=10;j++){
			c.x[i][j]=0;
		}
	}
	for(int k=0;k<=9;k++){
		for(int i=0;i<=9;i++){
			for(int j=0;j<=9;j++){
				c.x[i][j]=(c.x[i][j]+a.x[i][k]*b.x[k][j])%mod;
			}
		}
	}
	return c;
}
matr kpow(matr a,ll f){
	if(f==1) return a;
	matr tmp=kpow(a,f/2);
	tmp=tmp*tmp;
	if(f%2==1) tmp=tmp*a;
	return tmp;
}
int main(){
	freopen("sam.in","r",stdin);
	freopen("sam.out","w",stdout);
	scanf("%lld",&n);
	if(n==1){
		printf("10");
		return 0;
	}
	matr a,b;
	for(int i=0;i<=10;i++){
		for(int j=0;j<=10;j++){
			a.x[i][j]=0;
		}
	}
	for(int i=0;i<=10;i++){
		for(int j=0;j<=10;j++){
			b.x[i][j]=0;
		}
	}
	for(int i=1;i<=9;i++) b.x[0][i]=1;
	for(int i=0;i<=9;i++){
		for(int j=i-2;j<=i+2;j++){
			if(j<0) continue;
			if(j>9) continue;
			a.x[j][i]=1;
		}
	}
	b=b*kpow(a,n-1);
	ll ans=0;
	for(int i=0;i<=9;i++){
		ans=(ans+b.x[0][i])%mod;
	}
	printf("%lld",ans);
	return 0;
}
