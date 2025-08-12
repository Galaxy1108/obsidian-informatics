#include<bits/stdc++.h>
using namespace std;

#define sc scanf
#define pr printf
#define REP(a,b,c) for(int a = b;a <= c;++a)
#define DOW(a,b,c) for(int a = b;a >= c;--a)

typedef long long ll;

const int MAXN = 60;
const int MOD = 0;
struct Edge{
	int vis,vis2,to;
};
vector<Edge> G[MAXN];
vector<int> waym[MAXN];
vector<int> waytmp;
vector<Edge*> edm;
set<int> Gn;
int k;
bool fl;
void Dfs(int u,int nk,int v){
	if(nk == k+1){
		fl = true;
		return;
	}
	if(u == v){
		nk++;
		for(auto p : edm) p->vis2 = 1;
		return;
	}
	for(Edge &ed : G[u]){
		if(!(ed.vis || ed.vis2)){
			ed.vis = 1;
			waym[nk+1].push_back(u);
			Edge *p = &ed;
			edm.push_back(&ed);
			Dfs(ed.to,nk,v);
			if(fl) return;
			edm.pop_back();
			waym[nk+1].pop_back();
			ed.vis = 0;
		}
	}
}

int main(){

	int T;
	sc("%d",&T);
	while(T--){
		int n,m,u,v;
		sc("%d%d",&n,&m);
		k = ceil(1.0*m/(n-1));
		Gn.clear();
		REP(i,1,n) G[i].clear();
		REP(i,1,m){
			sc("%d%d",&u,&v);
			G[u].push_back({0,0,v}),G[v].push_back({0,0,u});
			Gn.insert(u),Gn.insert(v);
		}
		for(int p : Gn){
			if(fl) break;
			for(int pv : Gn){
				if(p != pv) fl = false,Dfs(p,0,pv);
				if(fl) break;
			}
		}
		REP(i,1,k){
			pr("%d ",waym[i].size()); 
			for(int p : waym[i]) pr(" %d",p);
			waym[i].clear();
			pr("\n");
		}
	}

	return 0;
}

