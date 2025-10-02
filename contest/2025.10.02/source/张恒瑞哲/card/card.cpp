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

const int MAXN = 35;
const int MOD = 0;

map<int,pair<bool,int>> mp;
map<int,bool> used;

int n,ans = INF,t[MAXN];
vector<int> a(MAXN);

void Dfs(int k){
	if(k == n+1){
		int ym = 0;
		REP(i,1,n) if(t[i]%2 != t[i-1]%2) ym++;
		ans = min(ans,ym);
		return;
	}
	if(mp[k].fi) return Dfs(k+1),void();
	REP(i,1,n){
		if(used[a[i]]) continue;
		t[k] = a[i]; 
		used[a[i]] = true;
		Dfs(k+1);
		used[a[i]] = false;
	}
}

int main(){

	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	int m,q,p,b,op; sc("%d%d%d",&n,&m,&q);
	REP(i,1,n) sc("%d",&a[i]);
	REP(i,1,m) sc("%d%d",&p,&b),mp[p].fi = true,mp[p].se = b;
	REP(i,1,q){
		sc("%d%d",&op,&p);
		if(op == 1) mp[p].fi = false;
		else sc("%d",&b),mp[p].fi = true,mp[p].se = b;
		for(auto& kk : used) kk.se = false;
		for(auto& kk : mp) if(kk.se.fi) used[kk.se.se] = true,t[kk.fi] = kk.se.se;
		ans = INF;
		Dfs(1);
		pr("%d\n",ans);
	}

	return 0;
}
