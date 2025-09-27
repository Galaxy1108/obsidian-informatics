#include<bits/stdc++.h>
using namespace std;

#define pr printf
#define sc scanf
#define REP(a,b,c) for(int a = (b);a <= (c);++a)
#define DOW(a,b,c) for(int a = (b);a >= (c);--a)
#define fi first
#define se second
#define Pb push_back

typedef long long ll;

const int INF = INT_MAX;
const long long LNF = LLONG_MAX;
const double Pi = 3.1415926535;
const double EPS = 1e-7;

const int MAXN = 400;
const int MOD = 0;

string MMs; int n;

int ans;
pair<int,char> MMa = {0,'0'},MMb = {0,'1'},MMc = {0,'2'};

void Dfs(int k,int p){
	if(k == n+1){
		REP(i,2,n) if(MMs[i] == MMs[i-1]) return;
		ans = min(ans,p);
		return;
	}
	if(p > ans) return;
	REP(i,1,n){
		swap(MMs[k],MMs[i]);
		Dfs(k+1,p+abs(i-k));
		swap(MMs[k],MMs[i]);
	}
}
 
void solve1(){
	pair<int,char> k = max(MMa,max(MMb,MMc));
	if(MMa.fi-1 > MMb.fi+MMc.fi) return pr("-1\n"),void();
	ans = INF;
	Dfs(1,0);
	pr("%d",ans == INF ? -1 : ans);
}

int main(){

	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	cin>>MMs; n = MMs.size();
	MMs = "="+MMs;	
	REP(i,1,n){
		if(MMs[i] == '0') ++MMa.fi;
		if(MMs[i] == '1') ++MMb.fi;
		if(MMs[i] == '2') ++MMc.fi;
	}
	solve1();
	
	return 0;
}
