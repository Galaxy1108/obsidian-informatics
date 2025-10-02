#include<bits/stdc++.h>
using namespace std;

#define pr printf
#define sc scanf
#define REP(a,b,c) for(int a = (b);a <= (c);++a)
#define DOW(a,b,c) for(int a = (b);a >= (c);--a)
#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> pii;

const int INF = INT_MAX;
const long long LNF = LLONG_MAX;
const double Pi = 3.1415926535;
const double EPS = 1e-7;

const int MAXN = 0;
const int MOD = 0;

template<typename T>
class SparseTable{
	private:
		vector<vector<T>> st;
		function<T(const T&,const T&)> func;

	public:
		SparseTable(const vector<T> &data,function<T(const T&,const T&)> f) : func(f){
			int n = data.size();
			int max_log = __lg(n)+1;
			st.assign(n, vector<T>(max_log));
			for(int i = 0;i < n;++i) st[i][0] = data[i];
			for(int j = 1;(1<<j) <= n;++j) for(int i = 0;i+(1<<j) <= n;++i) st[i][j] = func(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		}
		
	    T operator()(int L,int R) const{
	    	int p = __lg(R-L+1);
			return func(st[L][p],st[R-(1<<p)+1][p]);
		}
};

typedef SparseTable<int> ST;

int main(){

	freopen("drama.in","r",stdin);
	freopen("drama.out","w",stdout);

	int n; sc("%d",&n);
	vector<int> h(n+5);
	REP(i,1,n) sc("%d",&h[i]);
	ST stx(h,[](int a,int b){ return max(a,b); });
	ST sti(h,[](int a,int b){ return min(a,b); });
	ll ans = -LNF;
	REP(i,1,n){
		REP(j,i,min(i+950,n)){
			ll tmp = stx(i,j)*sti(i,j)*(j-i+1);
			if(tmp > ans) ans = tmp;
		}
	}
	pr("%lld",ans);

	return 0;
}
