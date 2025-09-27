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

const int MAXN = 1e5+5;
const int MOD = 0;

int a[MAXN],b[MAXN],nd,n,m;

bool check(int x){
	int p = 1,q = 1;
	while(p <= n && q <= m){
	//	pr("p = %d,q = %d\n",p,q);
		if(abs(a[p]-b[q]) <= x) p++;
		q++;
	}
	if(p == n+1) return true;
	else return false;
} 

int main(){
	
	freopen("gloves.in","r",stdin);
	freopen("gloves.out","w",stdout);
	
	sc("%d%d",&n,&m); nd = min(n,m);
	REP(i,1,n) sc("%d",&a[i]);
	REP(i,1,m) sc("%d",&b[i]);
	if(n > m) swap(a,b),swap(n,m);
	sort(a+1,a+1+n),sort(b+1,b+1+m);
	//	REP(i,1,n) pr("%d ",a[i]); pr("\n");
	//	REP(i,1,m) pr("%d ",b[i]); pr("\n");
	int l = 0,r = abs(b[m]-a[1]);
	while(l <= r){
		int m = (l+r)/2;
	//	pr("l = %d,r = %d,m = %d\n",l,r,m);
		if(check(m)) r = m-1;
		else l = m+1;
	}
	pr("%d",l);
	
	return 0;
}
