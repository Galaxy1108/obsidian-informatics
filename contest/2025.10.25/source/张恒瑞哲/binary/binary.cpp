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

template<typename T>
class FenwickTree{
	private :
		vector<T> tr; int n; inline int lowbit(int x){ return x&(-x); }
	public :
		FenwickTree(int mx) : n(mx),tr(mx+10) { }
		void update(int id,T val){ id++; for(;id <= n+3;id += lowbit(id)) tr[id] = tr[id]+val; }
		T query(int id){ id++; T ret = T(); for(;id > 0;id -= lowbit(id)) ret = ret+tr[id]; return ret; }
		T operator () (int l,int r){ return query(r)-query(l-1); }
};

int main(){

	freopen("binary.in","r",stdin);
	freopen("binary.out","w",stdout);

	int n,a; sc("%d",&n);
	bitset<1010> bt;
	FenwickTree<int> tr(n);
	REP(i,1,n){
		sc("%d",&a),bt[i] = a;
		if(a) tr.update(i,1);
	}
	int m; sc("%d",&m);
	REP(__,1,m){
		int t,l,r; sc("%d",&t);
		if(t == 1){
			sc("%d",&l);
			if(bt[l]) tr.update(l,-1);
			else tr.update(l,1);
			bt[l].flip();
//	pr(">>>"); REP(i,1,n) pr(bt[i]?"1 ":"0 "); pr("\n");
//	pr(">>>"); REP(i,1,n) pr("%d ",tr.query(i)); pr("\n");
		}
		else{
			int ans = 0;
			sc("%d%d",&l,&r);
			if(l > r) swap(l,r);
			REP(i,l,r){
				REP(j,i,r){
					int c1 = tr(i,j),len = j-i+1;
					if(c1 == 1) continue;
					if(!(c1&1)) ++ans;
					else if(len >= c1+2) ++ans;
				}
			}
			pr("%d\n",ans);
		}
	}

	return 0;
}
