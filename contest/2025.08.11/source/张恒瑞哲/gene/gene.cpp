#include<bits/stdc++.h>
using namespace std;

#define sc scanf
#define pr printf
#define REP(a,b,c) for(int a = b;a <= c;++a)
#define DOW(a,b,c) for(int a = b;a >= c;--a)

const int MAXN = 1e6+5;
const int INF = 1e9;


int G1[MAXN],G2[MAXN],a[MAXN];
int G1p[MAXN],G2p[MAXN];
struct Gene{
	int i,pos;
};
vector<Gene> ng1,ng2;
vector<Gene> g1,g2;

int main(){
	
	freopen("gene.in","r",stdin);
	freopen("gene.out","w",stdout);
	
	int n,l,r,tmp;
	sc("%d%d%d",&n,&l,&r);
	REP(i,1,n) sc("%d",&a[i]);
	REP(i,1,r){
		if(G1[a[i]] == 0) ng1.push_back({a[i],i});
		G1[a[i]]++;G1p[a[i]] = i;
	}
	REP(i,l,n){
		if(G2[a[i]] == 0) ng2.push_back({a[i],i});
		G2[a[i]]++;G2p[a[i]] = i;
	}
	for(Gene p : ng1) if(G1[p.i] == 1 && p.pos < l) g1.push_back({p.i,p.pos});
	for(Gene p : ng2) if(G2[p.i] == 1 && p.pos > r) g2.push_back({p.i,p.pos});
	sort(g1.begin(),g1.end(),[](Gene a,Gene b){ return a.pos > b.pos; });
	sort(g2.begin(),g2.end(),[](Gene a,Gene b){ return a.pos < b.pos; });
	int ans = INF;
	int cnt = 0;
	for(Gene p1 : g1){
		for(Gene p2 : g2){
			cnt++;
			if(p1.i != p2.i){
				if(G2[p1.i] == 1 && G2p[p1.i] < p2.pos) continue;
				if(G1[p2.i] == 1 && G1p[p2.i] > p1.pos) continue;
				ans = min(ans,p2.pos-p1.pos+1);
			}
			if(cnt > 3e8){
				pr("-1");
				return 0;
			}
			if(p2.pos-p1.pos+1 > ans) break; 
		}
	}
	if(ans == INF) pr("-1");
	else pr("%d",ans);

	return 0;
} 
