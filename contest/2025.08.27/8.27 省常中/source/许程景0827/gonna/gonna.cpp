#include <cstdio>
const int primes[34]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139};
int n,mod;
int qpow(int a,int b){
	int res=1;
	for(int i=31;~i;i--){
		res=(1ll*res*res)%mod;
		if(b&(1<<i)) res=(1ll*res*a)%mod;
	}
	return res;
}
int inv(int x){
	return qpow(x,mod-2);
}
int main(){
	freopen("gonna.in","r",stdin);
	freopen("gonna.out","w",stdout);
	scanf("%d%d",&n,&mod);
	int ans=0;
	for(int i=1;i<=n;i++){
		int ttans=1;
		for(int j=0;j<34;j++){
			#define p primes[j]
			int ans=0;
			for(int tmp=p;tmp<=n;tmp*=p){
				int tmp2=i/tmp;
				ans+=tmp*tmp2*(tmp2+1)-tmp2*(i+1);
			}
			// printf("<%d,%d>\n",p,ans);
			ttans=((1ll*ttans*(qpow(p,ans+1)-1)%mod)*inv(p-1))%mod;
		}
		ans=(ans+ttans)%mod;
	}
	printf("%d\n",ans);
}