#include<bits/stdc++.h>
using namespace std;

#define sc scanf
#define pr printf
#define REP(a,b,c) for(int a = b;a <= c;++a)
#define DOW(a,b,c) for(int a = b;a >= c;--a)

const int MAXN = 0;
typedef long long ll;

int main(){

	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	int T;
	ll S,tmp;
	sc("%d",&T);
	while(T--){
		sc("%lld%lld",&S,&tmp);
		if(S%2 == 1){
			if(2*tmp > S) pr("-1\n");
			else pr("%lld\n",2*tmp);
		}else{
			pr("-1\n");
		}
	}

	return 0;
}

