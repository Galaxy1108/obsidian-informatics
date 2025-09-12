#include<bits/stdc++.h>
using namespace std;

#define REP(a,b,c) for(int a = b;a <= c;++a)
#define DOW(a,b,c) for(int a = b;a >= c;--a)
#define sc scanf
#define pr printf
#define fi first
#define se second

typedef long long ll;
const int MAXN = 2e5+5;
#define int ll
struct Edge{
	int v; ll w;
};

vector<Edge> G[MAXN];
int col[MAXN];
ll Av[MAXN],Bv[MAXN],A,B;
bool isch[MAXN];

void rs(int u,int op){
	col[u] = op; 
	if(op == 1) A += Av[u];
	else B += Bv[u]; 
	for(const Edge& e : G[u]){
		if(col[e.v]) continue;
		int v = e.v; ll w = e.w;
		isch[v] = 1;
		if(op == 1) Av[v] -= w;
		else Bv[v] -= w;
	}
}

void solve(){
	int n,m,u,v,w; sc("%d%d",&n,&m);
	REP(i,1,n) G[i].clear(),isch[i] = col[i] = 0;
	REP(i,1,m){
		sc("%d%d%lld",&u,&v,&w);
		if(u == v){
			G[u].push_back({v,w});
		}else{
			G[u].push_back({v,w});
			G[v].push_back({u,w});		
		}
	}
	priority_queue<pair<ll,int>> pq;
	REP(i,1,n){
		ll tmp = 0;
		for(const Edge& e : G[i]) tmp += e.w;
		Av[i] = Bv[i] = tmp;
		pq.push({Av[i]+Bv[i],i});
	}
	int t;
//	REP(i,1,n) t = pq.top().se,pr("%d %d %d\n",t,Av[t],Bv[t]),pq.pop();
	
	A = 0,B = 0;
	int nowA = 1; 
	while(!pq.empty()){
		int nd = pq.top().se; pq.pop();
		
		while(isch[nd]){
			pq.push({Av[nd]+Bv[nd],nd});
			isch[nd] = false;
			nd = pq.top().se; pq.pop();
		}
	//	pr("%d %d %d %d\n",nowA,nd,Av[nd],Bv[nd]);
		if(nowA) rs(nd,1);
		else rs(nd,2);
		nowA ^= 1;
	}
	pr("%lld\n",abs(A-B));
}

signed main(){

	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int T; sc("%d",&T);
	while(T--) solve(); 

	return 0;
}

