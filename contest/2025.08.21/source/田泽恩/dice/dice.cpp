#include <bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
long long mul[5140],n,a[5140],ans;
long long fpow(long long x,long long y){
	long long base=1;
	while(y){
		if(y&1) base=base*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return base;
}
int main(){
	freopen("dice.in","r",stdin);
	freopen("dice.out","w",stdout);
	cin>>n;
	mul[0]=1;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;++i) mul[i]=mul[i-1]*a[i]%mod;
	for(long long i=1;i<=n;++i){
		long long res=mul[i-1];
		for(long long j=a[i-1]+1;j<=a[i];++j){
			long long res2=((fpow(j,n-i+1)-fpow(j-1,n-i+1))%mod+mod)%mod;
			ans=((ans+(res*res2%mod+mod)%mod*j%mod)%mod+mod)%mod;
		}
	}
	ans=ans*fpow(mul[n],mod-2)%mod;
	cout<<ans;
	return 0;
}
