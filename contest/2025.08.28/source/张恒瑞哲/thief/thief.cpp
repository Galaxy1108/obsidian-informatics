#include<bits/stdc++.h>
using namespace std;

#define sc scanf
#define pr printf
#define REP(a,b,c) for(int a = b;a <= c;++a)
#define DOW(a,b,c) for(int a = b;a >= c;--a)

typedef long long ll;

const int MAXN = 5e5+50;
const int MOD = 0;

int a[MAXN];

int main(){

	freopen("thief.in","r",stdin);
	freopen("thief.out","w",stdout);
	int n,m; sc("%d%d",&n,&m);
	REP(i,1,n) sc("%d",&a[i]);
	REP(i,1,m){
		int l,r,c; sc("%d%d%d",&l,&r,&c);
		REP(i,l,r){
			if(a[i] < c) --c;
			if(a[i] > c) ++c; 
		}
		pr("%d\n",c);
	}

	return 0;
}
