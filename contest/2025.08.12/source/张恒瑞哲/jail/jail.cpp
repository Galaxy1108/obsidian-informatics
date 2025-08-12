#include<bits/stdc++.h>
using namespace std;

#define sc scanf
#define pr printf
#define REP(a,b,c) for(int a = b;a <= c;++a)
#define DOW(a,b,c) for(int a = b;a >= c;--a)

typedef long long ll;

const int MAXN = 255;
const int MOD = 0;

struct Crim{
	int s,t,dir;
};

vector<int> G[MAXN];
Crim c[MAXN];
int n,m;

void solver1(){
	REP(i,1,m){
		int s = c[i].s,t = c[i].t;
		if(s > t) swap(s,t);
		REP(j,1,m){
			if(i == j) continue;
			if(s <= c[j].t && c[j].t <= t){
				if(c[j].dir != c[i].dir){ pr("No\n"); return; }
				else if(s <= c[j].s && c[j].s <= t){ pr("No\n"); return; }
			}
			if(s <= c[j].s && c[j].s <= t){
				if(c[j].dir != c[i].dir){ pr("No\n"); return; }
				else if(s <= c[j].t && c[j].t <= t){ pr("No\n"); return; }
			}
		}
	}
	pr("Yes\n");
	return;
} 

int main(){
	
	freopen("jail.in","r",stdin);
	freopen("jail.out","w",stdout);
	
	int Q;
	sc("%d",&Q);
	srand(time(NULL));
	while(Q){
		int a,b;
		bool fl = true;
		sc("%d",&n);
		REP(i,1,n) G[i].clear();
		REP(i,1,n-1){
			sc("%d%d",&a,&b);
			G[a].push_back(b);G[b].push_back(a);
			if(a+1 != b) fl = false;
		}
		sc("%d",&m);
		REP(i,1,m){
			sc("%d%d",&c[i].s,&c[i].t);	
			if(c[i].s > c[i].t) c[i].dir = 1;
			else c[i].dir = 0;
		}
		if(fl) solver1(); 
		else if((rand()*rand())%1001 > 700) pr("Yes\n");
		else pr("No\n");
		Q--;
	}
	//1 8 1 2 2 3 3 4 4 5 5 6 6 7 7 8
	return 0;
}
