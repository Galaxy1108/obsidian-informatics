#include<bits/stdc++.h>
using namespace std;

#define sc scanf
#define pr printf
#define REP(a,b,c) for(int a = b;a <= c;++a) 
#define DOW(a,b,c) for(int a = b;a >= c;--a)

typedef long long ll;

const int MAXN = 2e6+10; 
const int MOD = 0;

int read(){
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x;
}

class DSU{
	private :
		vector<int> fa,dep;
		
		int _find(int x){ return fa[x] == x ? x : fa[x] = _find(fa[x]); }
		
	public:
		DSU(int maxn) : fa(maxn),dep(maxn) {}
		
		void lineinsert(int n){ REP(i,1,n) fa[i] = i; }
		
		bool isconnect(int x,int y){ return _find(x) == _find(y); }
		
		void unite(int x,int y){
			x = _find(x),y = _find(y);
			if(x == y) return;
			if(dep[x] > dep[y]) swap(x,y);
			fa[x] = y;
			dep[y] += dep[x] == dep[y];
		}
};

DSU s(MAXN);
int t[MAXN];
 
int main(){
	
	freopen("virtual.in","r",stdin);
	freopen("virtual.out","w",stdout);
	int n,lk,rk; sc("%d%d%d",&n,&lk,&rk);
	s.lineinsert(n);
	REP(i,1,n){
		char c = '0'; 
		while(c != 'a' && c != 'b') c = getchar();
		t[i] = t[i-1];
		if(c == 'a') t[i] += 1;
	}
	int p = 1,q = 1,lstq = 0;
	REP(i,1,n){
		while(t[p]-t[i-1] < lk && p <= n) p++;
		if(p > n) break;
		while(t[q]-t[i-1] <= rk && q <= n) q++;
		q--;
		if(p <= lstq){
			s.unite(i,i-1);
			REP(j,lstq+1,q) s.unite(i,j);
		}
		else REP(j,p,q) s.unite(i,j);
		lstq = q; 
	}
	sc("%d",&q); 
	int u,v;
	while(q--){
		u = read(),v = read();
		if(s.isconnect(u,v)) pr("Yes\n");
		else pr("No\n");
	} 
	
	return 0;
} 
