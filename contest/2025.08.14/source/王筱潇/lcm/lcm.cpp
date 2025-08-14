#include <bits/stdc++.h>
#define ll long long
#define in __int128
ll T;
in g[30],f[30],ans[30];
using namespace std;
in gcd(in x,in y){
	if(x%y==0) return y; 
	return gcd(y,x%y);
} 
int main(){
	freopen("lcm.in","r",stdin);
	freopen("lcm.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		ll n,p;
		f[1]=1;
		f[2]=2;
		g[1]=1;
		g[2]=2;
		ans[1]=1;
		scanf("%lld%lld",&n,&p);
		for(int i=3;i<=20;i++){
			f[i]=2*f[i-1]+f[i-2];
			g[i]=g[i-1]*f[i]/gcd(g[i-1],f[i])%p;
		}
		for(int i=2;i<=20;i++){
			ans[i]=(ans[i-1]+(in)i*g[i]%p)%p;
		}
		printf("%lld\n",(ll)ans[n]);
	}
	return 0;
}
