#include <cstdio>
using namespace std;
long long mod;
long long qpow(long long a,long long b){
	long long res=1;
	for(int i=63;~i;i--){
		res=res*res/*%mod*/;
		if(b&(1ll<<i)) res=(a*res)/*%mod*/;
	}
	return res;
}
long long gcd(long long a,long long b){return b?gcd(b,a%b):a;}
long long inv(long long x){return qpow(x,mod-2);}
long long lcm(long long a,long long b){
	return ((a*b/*%mod*/)/gcd(a,b))/*%mod*/;
}
long long e[1000001],f[1000001];
int main(){
	freopen("lcm.in", "r", stdin);
	freopen("lcm.out", "w", stdout);
	e[0]=1ll;
	long long T,ans,x;
	scanf("%lld",&T);
	while(T--){
		ans=0;
		scanf("%lld%lld",&x,&mod);
		for (long long i=1ll;i<=x;i++){
			e[i]=(e[i-1]+(f[i-1]<<1)/*%mod*/)/*%mod*/;
			f[i]=(f[i-1]+e[i-1])/*%mod*/;
			printf("<%lld,%lld>\n",e[i],f[i]);
		}
		for(long long i=1ll,Lcm=1ll;i<=x;Lcm=lcm(Lcm,f[++i])){
			ans=(ans+i*Lcm/*%mod*/)/*%mod*/;
			printf("<%lld,%lld>",ans,Lcm);
		}
		printf("%lld\n",ans);
	}
}