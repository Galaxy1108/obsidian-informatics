#include<bits/stdc++.h>
using namespace std;

#define sc scanf
#define pr printf
#define REP(a,b,c) for(int a = b;a <= c;++a)
#define DOW(a,b,c) for(int a = b;a >= c;--a)

typedef long long ll;

const int MAXN = 2510;
const int MOD = 0;

struct MNUM{ int x,y; }a[MAXN];
bool vis[MAXN],f = false;
int n;
void Dfs(int k,int p){
	if(k == n){
		REP(i,1,n-1) pr("%d ",a[i].x*a[i].y); pr("%d\n",a[n].x);
		f = true;
		return;
	}
	REP(i,max(p-5,1),n){
		if(f) return;
		if(vis[i]) continue;
		if(__gcd(a[k-1].x,i) == 1){
			a[k].y = i,a[k+1].x = i;
			vis[i] = true;
			Dfs(k+1,i+1);
			vis[i] = false;
		}
	}
}

int main(){
	
	freopen("divisors.in","r",stdin);
	freopen("divisors.out","w",stdout);
	sc("%d",&n);
	a[0].x = 1;
	a[1].x = 1,vis[1] = true;
	Dfs(1,0);
	REP(i,1,n-1){
		pr("%d %d\n",i,i+1);
	}
	
	return 0;
} 
