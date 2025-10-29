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

bitset<30> vis,use;
int a[30],n,ans;

map<vector<int>,int> hv;

void Dfs(int k){
	if(k == n+1){
		vector<int> b;
		REP(i,1,n/2) b.Pb(min(a[2*i],a[2*i-1]));
		if(!hv.count(b)) ++ans;
		hv[b] = 1;
		return;
	}
	if(vis[k]) return Dfs(k+1),void();
	REP(i,1,n){
		if(use[i]) continue;
		use[i] = 1; a[k] = i;
		Dfs(k+1);
		use[i] = 0;
	}
}

int main(){

	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);

	sc("%d",&n); n *= 2;
	REP(i,1,n){
		sc("%d",&a[i]);
		if(a[i] != -1) use[a[i]] = vis[i] = 1;
	}
	Dfs(1);
	pr("%d",ans);

	return 0;
}
