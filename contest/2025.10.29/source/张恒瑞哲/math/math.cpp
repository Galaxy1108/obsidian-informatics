#include <bits/stdc++.h>
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
const double EPS = 1e-7;
const int REEPS = 1e7;
const double Pi = 3.1415926535;

const int MAXN = 1050;
const int MOD = 0;

vector<int> ans,cur;
bool IDAdfs(int d,ll a,ll b,int e){
	if(d == 0){
		if(a == 0 && ans.empty()) ans = cur;
		return a == 0;
	}
	ll tmp = __gcd(a,b); a /= tmp,b /= tmp;
	bool f = false;
	int e1 = max(e+1,int((b+a-1)/a));
	if(b > a*REEPS) return false;
	for(;;e1++){
		if(d*b < a*e1) return f;
		cur.Pb(e1);
		f = f|IDAdfs(d-1,a*e1-b,b*e1,e1);
		cur.pop_back();
	}
	return f;
}

int main(){
	
    freopen("math.in","r",stdin);
	freopen("math.out","w",stdout);
    
	int a,b; sc("%d%d",&a,&b);
    ans.clear(); cur.clear();
    int cnt = 0;
    REP(p,1,100){
        if(IDAdfs(p,a,b,1)){
            cnt = p; break;
        }       
    }
    pr("%d\n",cnt);
    REP(i,0,cnt-1) pr("%d ",ans[i]);

	return 0;
}