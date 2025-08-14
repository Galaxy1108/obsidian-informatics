#include<bits/stdc++.h>
using namespace std;

#define REP(a,b,c) for(int a = b;a <= c;++a)
#define DOW(a,b,c) for(int a = b;a >= c;--a)
#define sc scanf
#define pr printf

typedef long long ll;

const int MAXN = 0;
const int MOD = 0;

int main(){

	freopen("calc.in","r",stdin);
	freopen("calc.out","w",stdout);
	int T,p;
	sc("%d%d",&T,&p);
	REP(i,1,T){
		int x;
		sc("%d",&x);
		if(p == 2) pr(x%2 == 0 ? "-1" : "1");
		else if(p == 3) pr(x%3 == 2 ? "2" : "-1");
		else if(p == 5){
			if(x%5 == 4) pr("2");
			else if(x%5 <= 1) pr("-1");
			else pr("1");
		}
		else pr("-1");
		pr("\n");
	}
	
	return 0;
}

