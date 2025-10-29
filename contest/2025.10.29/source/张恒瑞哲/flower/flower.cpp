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

const int MAXN = 50;
const int MOD = 0;

string s[MAXN];
vector<int> mj[MAXN];
int use[MAXN],n,ans[MAXN<<1];
int jzpd[MAXN<<1];
bool f = false;

void Dfs(int k){
    //pr("%3d->",k); REP(i,1,2*n) pr("%3d ",ans[i]); pr("\n");
    if(f) return;
    if(k == 2*n+1){
        f = true;
        REP(i,1,2*n) cout<<s[ans[i]]<<"\n";
        return;
    }
    if(ans[k]) return Dfs(k+1),void();
    DOW(i,n,1){
    	if(i+k+1 > 2*n) continue;
        if(use[i]) continue;
        if(ans[k+i+1]) continue; 
        ans[k] = i; ++use[i];
        ans[k+i+1] = i;
        Dfs(k+1);
        ans[k+i+1] = 0;
        ans[k] = 0; --use[i];
    }
}

int main(){

	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);

    sc("%d",&n);
    REP(i,1,n) cin>>s[i];
    Dfs(1);
    if(!f) pr("wj\n");

    return 0;
}