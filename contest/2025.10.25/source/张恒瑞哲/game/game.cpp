#include<bits/stdc++.h>
using namespace std;

#define pr printf
#define sc scanf
#define REP(a,b,c) for(int a = (b);a <= (c);++a)
#define DOW(a,b,c) for(int a = (b);a >= (c);--a)
#define Pb push_back
#define Eb emplace_back
#define Sz(v) (int(v.size()))
#define FALL(v) v.begin(),v.end()
#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> P2i;
typedef vector<int> Vi;

const int INF = INT_MAX;
const long long LNF = LLONG_MAX;
const double Pi = 3.1415926535;
const double EPS = 1e-7;

const int MAXN = -1;
const int MOD = 0;

void solve1(int n){
	if(n&1) pr("%d",n);
	else pr("0");
}

int main(){

	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);

	int n; sc("%d",&n);
	vector<int> a(n+1);
	bool is_1 = true;
	REP(i,1,n) sc("%d",&a[i]),is_1 = is_1 && (a[i] == 1);
	if(is_1) solve1(n);
	else{
		if(n == 1) pr("%d",a[1]-int(ceil(1.0*a[1]/2))+1);
		else{
			int ans = 0;
			REP(i,1,n){
				if(a[i] == 1) continue;
				ans += a[i]-int(ceil(1.0*a[i]/2))+1;
				if(a[i]%2 == 0) --ans;
			}
			pr("%d",ans);
		}
	}
	return 0;
}
