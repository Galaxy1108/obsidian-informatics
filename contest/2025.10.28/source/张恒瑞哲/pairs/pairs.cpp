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

const int MAXN = 1024;
const int MOD = 1024;

template<typename T>
class FenwickTree{
    private :
        vector<T> tr; int n; inline int lowbit(int x){ return x&(-x); }
    public :
        FenwickTree(int mx) : n(mx),tr(mx+10) { }
        void update(int id,T val){ id++; for(;id <= n+3;id += lowbit(id)) tr[id] = tr[id]+val; }
        T query(int id){ id++; T ret = T(); for(;id > 0;id -= lowbit(id)) ret = ret+tr[id]; return ret; }
};

int a[15];

int main(){

	freopen("pairs.in","r",stdin);
	freopen("pairs.out","w",stdout);

    int n,cnt = 1,pc,md = 1e9+7;
    sc("%d%d",&n,&md);
    REP(i,1,n) cnt *= i,a[i] = i; pc = cnt;
    vector<vector<int>> p;
    while(cnt--){
        next_permutation(a+1,a+1+n);
        vector<int> tmp;
        REP(i,1,n) tmp.Pb(a[i]);
        p.Pb(tmp);
    }
    sort(FALL(p));
    vector<int> nxd(1026,0);
    int j = 0;
    for(auto vec : p){
        ++j;
        FenwickTree<int> tr(n+5);
        for(auto x : vec){
            tr.update(x,1);
            nxd[j] += (tr.query(n+2)-tr.query(x));
        }
    }
    int ans = 0;
    REP(p,1,pc){
        REP(q,p+1,pc){
            if(nxd[p] > nxd[q]) ++ans;
        }
    }
    pr("%d",ans%md);

    return 0;
}