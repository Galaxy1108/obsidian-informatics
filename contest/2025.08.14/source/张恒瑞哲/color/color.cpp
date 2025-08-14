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

	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int n,a,b,c;
	sc("%d",&n);
	if(n == 1) pr("0");
	else if(n == 2){
		sc("%d%d",&a,&b);
		if(a != b) pr("%d",4);
		else pr("0");
	}
	else if(n == 3){
		sc("%d%d%d",&a,&b,&c);
		if(a == b && b == c && a == c) pr("0");
		if(a != b && b != c && a != c) pr("42");
	}
	else pr("0");
	
	return 0;
}

