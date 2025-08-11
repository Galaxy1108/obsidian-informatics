#include<bits/stdc++.h>
using namespace std;

#define sc scanf
#define pr printf
#define REP(a,b,c) for(int a = b;a <= c;++a)
#define DOW(a,b,c) for(int a = b;a >= c;--a)
#define ll long long

const int MAXN = 2e5+5;
const int MAXQ = 1e6;
const int MOD = 0;

struct Question{
	int t,i,ans,id;
}q[MAXQ];

int n,Q,t = 0;
int a[2][MAXN];
//bool fl = false; 

void solve(){
//	if(fl){
//		++t;return;	
//	}
	int ff = true;
	int ko = t%2,kn = (ko+1)%2;
	int p = 1,i = 1,j = n/2+1;
	while(true){
		if(i > n/2 || j > n) break;
		if(a[ko][i] < a[ko][j]){
			a[kn][p] = a[ko][i];
			++i;
		}else{
			a[kn][p] = a[ko][j];
			++j;
		}
		if(a[kn][p] != a[ko][p]) ff = false;
		++p;
	}
	++t;
	if(i == n/2+1) while(j != n+1) a[kn][p] = a[ko][j],++j,++p;
	if(j == n+1) while(i != n/2+1) a[kn][p] = a[ko][i],++i,++p;	
//	if(ff) fl = true;
//	REP(kk,1,n) pr("%d ",a[kn][kk]);
//	pr("\n");
}

int main(){

//	freopen("magic.in","r",stdin);
//	freopen("magic.out","w",stdout);
	sc("%d%d",&n,&Q);
	REP(i,1,n) sc("%d",&a[0][i]);
	REP(i,1,Q) sc("%d%d",&q[i].t,&q[i].i),q[i].id = i;
	sort(q+1,q+1+Q,[](Question a,Question b){ return a.t == b.t ? a.i < b.i : a.t < b.t;});
	REP(i,1,Q){
		while(q[i].t != t) solve();
		q[i].ans = a[t%2][q[i].i];
	}
	sort(q+1,q+1+Q,[](Question a,Question b){ return a.id < b.id;});
	REP(i,1,Q) pr("%d\n",q[i].ans);
	

	return 0;
}

