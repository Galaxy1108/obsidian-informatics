#include<bits/stdc++.h>
using namespace std;

#define sc scanf
#define pr printf
#define REP(a,b,c) for(int a = b;a <= c;++a)
#define DOW(a,b,c) for(int a = b;a >= c;--a)

typedef long long ll;

const int MAXN = 2.5e5+5;
const int MOD = 998244353;
int n;
ll A[MAXN],B[MAXN],C[MAXN];

int main(){

	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	sc("%d",&n);
	REP(i,1,n) sc("%lld%lld%lld",&A[i],&B[i],&C[i]);
	int m,op,l,r,v; sc("%d",&m);
	ll na,nb,nc;
	REP(mcnt,1,m){
		sc("%d%d%d",&op,&l,&r);
		if(op == 1) REP(i,l,r) A[i] += B[i],A[i] %= MOD;
		else if(op == 2) REP(i,l,r) B[i] += C[i],B[i] %= MOD;
		else if(op == 3) REP(i,l,r) C[i] += A[i],C[i] %= MOD;
		else if(op == 7){ na = nb = nc = 0; REP(i,l,r) na += A[i],nb += B[i],nc += C[i],na %= MOD,nb %= MOD,nc %= MOD; pr("%lld %lld %lld\n",na,nb,nc); }
		else{
			sc("%d",&v);
			if(op == 4) REP(i,l,r) A[i] += v,A[i] %= MOD;
			else if(op == 5) REP(i,l,r) B[i] *= v,B[i] %= MOD;
			else REP(i,l,r) C[i] = v,C[i] %= MOD;
		}
	}

	return 0;
}
