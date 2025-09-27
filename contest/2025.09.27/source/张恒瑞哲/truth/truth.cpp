#include<bits/stdc++.h>
using namespace std;

#define pr printf
#define sc scanf
#define REP(a,b,c) for(int a = (b);a <= (c);++a)
#define DOW(a,b,c) for(int a = (b);a >= (c);--a)

typedef long long ll;

const int INF = INT_MAX;
const long long LNF = LLONG_MAX;
const double Pi = 3.1415926535;
const double EPS = 1e-7;

const int MAXN = 5e4+10;
const int MOD = 0;

int a[MAXN],cnt[30][MAXN];

int main(){

	freopen("truth.in","r",stdin);
	freopen("truth.out","w",stdout);
	int n,k,m; sc("%d%d%d",&n,&k,&m);
	REP(i,1,n){
		sc("%d",&a[i]);
		REP(j,0,k) cnt[j][i] = cnt[j][i-1];
		cnt[a[i]][i]++;
	}
//	REP(j,1,k){
//		REP(i,1,n){
//			pr("%d ",cnt[j][i]);
//		}
//		pr("\n");
//	}

	while(m--){
		int op,p,v; sc("%d",&op);
		if(op == 1){
			sc("%d%d",&p,&v),a[p] = v;
			REP(i,1,n){
				REP(j,0,k) cnt[j][i] = cnt[j][i-1];
				cnt[a[i]][i]++;
			} 
			
		}
		if(op == 2){
			int len = INF;
			REP(i,1,n){
				REP(j,i,n){
					bool f = true;
					REP(q,1,k) if(cnt[q][j]-cnt[q][i-1] <= 0){ f = false; break; }
					if(f) len = min(len,j-i+1);
				}
			}
			pr("%d\n",len == INF ? -1 : len);
		}
	}

	return 0;
}
