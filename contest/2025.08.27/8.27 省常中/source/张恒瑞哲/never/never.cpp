#include<bits/stdc++.h>
using namespace std;

#define sc scanf
#define pr printf
#define REP(a,b,c) for(int a = b;a <= c;++a)
#define DOW(a,b,c) for(int a = b;a >= c;--a)
typedef long long ll;

const int MAXN = 0;
const int MOD = 0;

//int pow(int a, int b) {
//	int res;
//	for (; b; b >>= 1) {
//		if (b & 1) res = res * a;
//		a = a * a;
//	}
//	return res;
//}
//
//int euclid(int a,int b,int c,int n,int U,int R) {
//	if (b >= c) return pow(U,b/c)*euclid(a,b%c,c,n,U,R);
//	if (a >= c) return euclid(a%c,b,c,n,U,pow(U,a/c)*R);
//	auto m = ((long long)a*n+b)/c;
//	if(!m) return pow(R,n);
//	return pow(R,(c-b-1)/a)*U*euclid(c,(c-b-1)%a,a,m-1,R,U)*pow(R,n-(c*m-b-1)/a);
//}


int main() {

	freopen("never.in","r",stdin);
	freopen("never.out","w",stdout);
	int T,n,s,t,a,b;
	sc("%d",&T);
	while(T--){
		sc("%d%d%d%d%d",&n,&s,&t,&a,&b);
		while(n--){
			if(s >= t) s -= a;
			else s += b;
		}
		pr("%d\n",s);
	}


	return 0;
}
