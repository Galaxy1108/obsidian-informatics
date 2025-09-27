#include<bits/stdc++.h>
using namespace std;

#define pr printf
#define sc scanf
#define REP(a,b,c) for(int a = (b);a <= (c);++a)
#define DOW(a,b,c) for(int a = (b);a >= (c);--a)

typedef long long ll;

const int INF = INT_MAX;
const long long LNF = LLONG_MAX;
const double Pi = 3.1415926535;
const double EPS = 1e-7;

const int MAXN = 1e5+10;
const int MOD = 0;

int a[MAXN],n;

void solve1(){
	int ans = 0;
	REP(i,1,n){
		REP(j,i,n){
			int sum = a[i],mx = a[i];
			REP(k,i+1,j) sum ^= a[k],mx = max(mx,a[k]);
			if(sum <= mx) ans++;
		}
	}
	pr("%d\n",ans);
}

int main(){

	freopen("xor.out","r",stdin);
	freopen("xor.out","w",stdout);

	int mx = -INF;
	sc("%d",&n); REP(i,1,n) sc("%d",&a[i]),mx = max(a[i],mx);
	if(n <= 2e3+10) return solve1(),0; 

	return 0;
}
