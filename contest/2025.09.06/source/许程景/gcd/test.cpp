#include <cstdio>
#define mod 998244353
int inv(int x){
    int res=1;
    for(int i=31;~i;i--){
	res=(1ll*res*res)%mod;
	if((mod-2)&(1<<i)) res=(1ll*res*x)%mod;
    }
    return res;
}
int main(){
    int a,b;
    scanf("%d/%d",&a,&b);
    printf("%lld\n",(1ll*a*inv(b))%mod);
}
