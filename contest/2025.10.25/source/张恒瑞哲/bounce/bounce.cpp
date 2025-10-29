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

const int MAXN = 1e3+10;
const int MOD = 0;

bitset<MAXN> bt,tp;

int main(){

	freopen("bounce.in","r",stdin);
	freopen("bounce.out","w",stdout);

	int n,q; sc("%d%d",&n,&q);
	bt.reset();
	REP(i,1,n) bt[i] = 1;
	REP(i,1,q){
		int t,m; sc("%d%d",&t,&m);
		if(t == 1){
			for(int i = 1;i <= n;i += m) bt[i] = 0;
		}
		if(t == 2){
			int p,cnt = 0;
			REP(i,1,n) if(bt[i]){ p = i,bt[i] = 0; break; }
			REP(i,p,n){
				cnt += bt[i];
				if(cnt == m) bt[i] = cnt = 0; 
			}
		}
		if(t == 3){
			tp = bt; int ans = -1;
		//	int ct = tp.count();
		//	pr("ct = %d\n",ct);
			while(tp.count()){
				int p = n+1,cnt = 0;
				REP(i,1,n) if(tp[i]){ ans = p = i,tp[i] = 0; break; }
				REP(i,p,n){
					cnt += tp[i];
					if(cnt == m) tp[i] = cnt = 0,ans = i; 
				}
				p = -1,cnt = 0;
				DOW(i,n,1) if(tp[i]){ ans = p = i,tp[i] = 0; break; }
				DOW(i,p,1){
					cnt += tp[i];
					if(cnt == m) tp[i] = cnt = 0,ans = i; 
				}		
			}
			pr("%d\n",ans);
		}
		//REP(i,1,n) pr(bt[i]?"I":"o"); pr("\n");
	}
	

	return 0;
}
