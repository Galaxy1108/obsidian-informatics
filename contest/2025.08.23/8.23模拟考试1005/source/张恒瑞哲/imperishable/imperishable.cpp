#include<bits/stdc++.h>
using namespace std;

#define sc scanf
#define pr printf
#define REP(a,b,c) for(int a = b;a <= c;++a)
#define REP(a,b,c) for(int a = b;a <= c;++a)

typedef long long ll;

const int MAXN = 20;

const ll MOD = 998244353;

struct Mul_set{
	int t[15],id;
	
	void clear(){
		REP(i,1,11) t[i] = 0;
		id = 0;
	}
	
	void insert(int x){
		t[x]++;
		if(t[id] < t[x]) id = x;
		if(t[id] == t[x]) id = min(id,x);
	}
	
	int getans(){
		if(id == 0) return 0;
		ll ret = 1; REP(i,1,id) ret *= 2,ret %= MOD;
		return ret; 
	}
	
	void operator = (const Mul_set& s1){
		REP(i,1,11) t[i] = s1.t[i];
		id = s1.id;
	}
}s[MAXN];

int a[155],cnt[20],n,zn = 0;
ll ans = 1e9;

void Dfs(int k){
	if(k == zn+1){
		ll tmp = 0;
		REP(i,1,n) tmp += s[i].getans(),tmp %= MOD;
		ans = min(ans,tmp);
		return;
	}
	Mul_set ts1;
	REP(i,1,n){
		ts1 = s[i];
		s[i].insert(a[k]);
		Dfs(k+1);
		s[i] = ts1;
	}
}

int main(){

	freopen("imperishable.in","r",stdin);
	freopen("imperishable.out","w",stdout);
	int Qnum; sc("%d",&Qnum);
	if(Qnum == 1){ pr("2\n"); return 0; }
	int q; sc("%d",&n);
	REP(i,1,n){ sc("%d",&cnt[i]); REP(j,zn+1,zn+cnt[i]) a[j] = i; zn += cnt[i]; }  
	ans = 1e9; Dfs(1); pr("%lld\n",ans);
//	REP(i,1,zn) pr("%d ",a[i]);
	sc("%d",&q);
	REP(i,1,q){
		int xx,yy; sc("%d%d",&xx,&yy); cnt[xx] = yy; zn = 0;
		REP(i,1,n){ REP(j,zn+1,zn+cnt[i]) a[j] = i; zn += cnt[i]; }  
		ans = 1e9; REP(i,1,n) s[i].clear();
		Dfs(1);
		pr("%lld\n",ans);
	}

	return 0;
}
