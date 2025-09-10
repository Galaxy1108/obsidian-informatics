#include<bits/stdc++.h>
using namespace std;

#define pr printf
#define sc scanf
#define REP(a,b,c) for(int a = b;a <= c;++a)
#define DOW(a,b,c) for(int a = b;a >= c;--a)
#define fi first
#define se second

typedef long long ll;

const int INF = INT_MAX;
const long long LNF = LLONG_MAX;
const double Pi = 3.1415926535;
const double EPS = 1e-7;

const int MAXN = 0;
const int MOD = 0;

int ac,bc,zc;

void Dfs(int w,int b,int f,int kc){
//	REP(ff,1,kc) REP(j,1,4) pr(" ");
//	pr("%d %d %d\n",w,b,f);
	if(w == 0 && b == 0){
//		REP(ff,1,kc+15) REP(j,1,4) pr(" ");
//		pr("B\n");
		bc++;
		zc++;
		return;
	}
	if(b > 0){
		if(f){
			Dfs(w,b-1,f^1,kc+1);
		}else{
			if(w >= 1) Dfs(w-1,b-1,f^1,kc+1);
			if(b-1 >= 1) Dfs(w,b-2,f^1,kc+1);
		}
	}	
	if(w > 0){
//		REP(ff,1,kc+1) REP(j,1,4) pr(" ");
//		if(f) pr("A\n");
//		else pr("B\n");
		if(f) ac++;
		else bc++;
		zc++;
		return;
	}
}

int main(){

	freopen("mouse.in","r",stdin);
	freopen("mouse.out","w",stdout);

	int w,b; sc("%d%d",&w,&b);
	Dfs(w,b,1,0);
//	pr("%d %d %d\n",ac,bc,zc);
	pr("%.9f",ac*1.0/(ac+bc));

	return 0;
}
