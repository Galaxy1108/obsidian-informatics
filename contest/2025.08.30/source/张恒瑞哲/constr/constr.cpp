#include<bits/stdc++.h>
using namespace std;

#define sc scanf
#define pr printf
#define REP(a,b,c) for(int a = b;a <= c;++a)
#define DOW(a,b,c) for(int a = b;a >= c;--a)

typedef long long ll;

const int MAXN = 0;
const int MOD = 0;

int main(){

	freopen("constr.in","r",stdin);
	freopen("constr.out","w",stdout);
//20 12345-13
//200 114515-20	
//420 934515-23 3 5 6 8 9 7 1 2 10 4->3 5 8 6 9 7 1 2 10 4
	int a[10];
	int j = 420;
	pr("%d\n",j);
	srand(934515);
	REP(i,0,9) a[i] = i+1;
	while(j--){
		if(j == 418) pr("3 5 8 6 9 7 1 2 10 4");
		else REP(i,0,9) pr("%d ",a[i]);
		pr("\n");
		random_shuffle(a,a+10);
	}

	return 0;
}
