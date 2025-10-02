#include<bits/stdc++.h>
using namespace std;

#define pr printf
#define sc scanf
#define REP(a,b,c) for(int a = (b);a <= (c);++a)
#define DOW(a,b,c) for(int a = (b);a >= (c);--a)
#define fi first
#define se second
typedef long long ll;

const int INF = INT_MAX;
const long long LNF = LLONG_MAX;
const double Pi = 3.1415926535;
const double EPS = 1e-7;

const int MAXN = 100;
const int MOD = 0;

int a[MAXN],tmp[MAXN],n,T;
typedef pair<int,int> pii;


int main(){

	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	sc("%d%d",&T,&n);
	REP(i,1,n) sc("%d",&a[i]),tmp[i] = a[i];
	if(n != 3) return 0;
	sort(tmp+1,tmp+1+3);
	if(tmp[3]-tmp[1] >= tmp[2]) pr("1\n");
	else pr("3\n");
	REP(tt,1,T-1){
		int k,u,v; sc("%d",&k);
		REP(i,1,k) sc("%d %d",&u,&v),a[u] = v;
		REP(i,1,n) tmp[i] = a[i];
		sort(tmp+1,tmp+1+3);
		if(tmp[3]-tmp[1] >= tmp[2]) pr("1\n");
		else pr("3\n");
	}

	return 0;
}
