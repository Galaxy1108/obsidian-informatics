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

const int MAXN = 0;
const int MOD = 0;

int n,x;

int ans;
vector<int> a(10);

void Dfs(int k){
    if(k == n+1){
        int cnt = n;
        vector<int> b(a);
        bool hav = false;
        while(cnt > 0){
            int tmp = 0;
            REP(i,1,n){
                if(b[i] > 0 && b[i]-(cnt-1) <= 0) b[i] -= cnt-1,++tmp;
                else b[i] -= cnt-1;
            }
            cnt -= tmp;
            if(cnt == 1){ hav = true; break; }
        }
        if(!hav){ ++ans; }
        return;
    }
    REP(i,1,x) a[k] = i,Dfs(k+1);
}

void solve_BFS(){ Dfs(1),pr("%d",ans); }

//dp[k][x] 有k人，最高x
//dp[k][x] = IncExcP(sum(p:1~x-1) dp[k][x-p])+dp[k-1][x]*(k-1)

int main(){

	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);

    sc("%d%d",&n,&x);
    if(n <= 5 && x <= 20) solve_BFS();

    return 0;
}
