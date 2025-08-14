#include<bits/stdc++.h>
using namespace std;

#define REP(a,b,c) for(int a = b;a <= c;++a) 
#define DOW(a,b,c) for(int a = b;a >= c;--a)
#define sc scanf
#define pr printf

typedef long long ll;

const int MAXN = 300;
const int MOD = 0;

__int128 f[MAXN],g[MAXN];

int main(){
	
	freopen("lcm.in","r",stdin);
	freopen("lcm.out","w",stdout);
	int T;
	sc("%d",&T);
	f[1] = 1,f[2] = 2,g[1] = 1,g[2] = 2;
	while(T--){
		int n,p;
		sc("%d %d",&n,&p);
		__int128 mo = p;
		REP(i,3,n){
			f[i] = (f[i-2]+2*f[i-1]);
			g[i] = (g[i-1]*f[i])/__gcd(g[i-1],f[i]);
		}
		__int128 ans = 0;
		REP(i,1,n) ans = (ans+g[i]*i%mo)%mo;
		ll fans = ans;
		pr("%lld\n",fans);
	}
	
//	REP(i,1,10) pr("%d ",e[i]);
//	pr("\n");
//	REP(i,1,10) pr("%d ",f[i]);
//	pr("\n");
//	REP(i,1,10) pr("%d ",g[i]);

	return 0;
} 
