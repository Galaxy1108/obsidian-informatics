#include<bits/stdc++.h>
using namespace std;

#define sc scanf
#define pr printf
#define REP(a,b,c) for(int a = b;a <= c;++a)
#define DOW(a,b,c) for(int a = b;a >= c;--a)

const int MAXN = 1000;
const int MOD = 0;

int h[MAXN],h_[MAXN],p[MAXN],q[MAXN],n;
bitset<MAXN> used;

void solve1(){
	REP(i,1,n) h[i] = i;
	int cnt = 1; REP(i,1,n) cnt *= i;
	while(cnt--){
		bool f = true;
		REP(i,1,n) h_[h[i]] = i;
		REP(i,1,n){
			if(h_[p[h[i]]] != q[i]){
				f = false;
				break;
			}
		}
		if(f){
			pr("YES\n");
			REP(i,1,n) pr("%d ",h[i]);
			return;
		}else{
			next_permutation(h+1,h+1+n);
		}
	}
	pr("NO");
}

//void Dfs(int k){
//	if(k == n+1){
//		pr("YES\n");
//		REP(i,1,n) pr("%d ",h[i]);
//		pr("\n");
//		return;
//	}
//	if(h[k] != -1) Dfs(k+1);
//	else REP(i,1,n){
//		if(used[i]) continue;
//		if(h[q[k]] != -1) if()
//		h[k] = i;
//		
//		used[i] = true;
//		Dfs(k+1);
//		used[i] = false;
//		h[k] = -1;
//		if(i != n) h[q[k]] = -1,used[i+1] = false;
//		else h[q[k]] = -1,used[1] = false;
//	}
//}
//
//void solve2(){
//	REP(i,1,n) h[i] = -1;
//	Dfs(1);
//	pr("NO");
//}

int main(){

	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	sc("%d",&n);
	REP(i,1,n) sc("%d",&p[i]);
	REP(i,1,n) sc("%d",&q[i]);
	if(n <= 15) solve1();
//	else solve2();
	
	return 0;
}
