#include<bits/stdc++.h>
using namespace std;

#define sc scanf
#define pr printf
#define REP(a,b,c) for(int a = b;a <= c;++a)
#define DOW(a,b,c) for(int a = b;a >= c;--a)

#define il 1ll*

typedef long long ll;

const int MAXN = 5e4+5;
const int MOD = 998244353;

int inv[MAXN];

void invinit(int n,int p){
	inv[1] = 1; 
	REP(i,2,n) inv[i] = il (long long)(p-p/i)*inv[p%i]%p;
} 

int main(){
	
	freopen("youup.in","r",stdin);
	freopen("youup.out","w",stdout);
	int Num,n,x; sc("%d",&Num); sc("%d%d",&n,&x);
	if(Num == 1 || x == 0){ pr("%d ",n); REP(i,2,n) pr("0 "); return 0;}
	if(Num == 4){
		if(x == 1){ pr("%d %d ",n,n-1); REP(i,3,n) pr("0 "); return 0;}
		if(x >= 2){
			invinit(n,MOD);
			ll ans = 1;
			REP(i,1,n) ans = ans* il (n-i+1)%MOD* il inv[i]%MOD,pr("%lld ",ans);
		}
		return 0;
	}
	
	return 0;
}
