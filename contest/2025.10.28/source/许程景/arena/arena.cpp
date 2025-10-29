#include <cstdio>
#define mod 998244353
int qpow(int a,int b){
    int res=1;
    for(int i=30;~i;i--){
	res=(1ll*res*res)%mod;
	if(b&(1<<i)) res=(1ll*res*a)%mod;
    }
    return res;
}
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d\n",qpow(b,a));
}
