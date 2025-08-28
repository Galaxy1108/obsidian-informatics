#include<bits/stdc++.h>
using namespace std;

#define sc scanf
#define pr printf
#define REP(a,b,c) for(int a = b;a <= c;++a)
#define DOW(a,b,c) for(int a = b;a >= c;--a)

typedef long long ll;

#define int ll

const int MAXN = 2e5 +10;
const int MOD = 0;

int t,n;
int a[MAXN],mx[MAXN<<2],se[MAXN<<2],cn[MAXN<<2],tag[MAXN<<2];
long long sum[MAXN<<2];

void pushup(int u){
	int ls = u<<1,rs = u<<1|1;
	sum[u] = sum[ls]+sum[rs];
	if(mx[ls] == mx[rs]) mx[u] = mx[rs],se[u] = max(se[ls],se[rs]),cn[u] = cn[ls]+cn[rs];
	else if(mx[ls] > mx[rs]) mx[u] = mx[ls],se[u] = max(se[ls],mx[rs]),cn[u] = cn[ls];
	else mx[u] = mx[rs],se[u] = max(mx[ls], se[rs]),cn[u] = cn[rs];
}

void pushtag(int u,int tg) {
	if(mx[u] <= tg) return;
	sum[u] += (1ll*tg-mx[u])*cn[u];
	mx[u] = tag[u] = tg;
}

void pushdown(int u){
	if(tag[u] == -1) return;
	pushtag(u<<1,tag[u]),pushtag(u<<1|1,tag[u]);
	tag[u] = -1;
}

void build(int u = 1,int l = 1,int r = n){
	tag[u] = -1;
	if(l == r){ sum[u] = mx[u] = a[l], se[u] = -1, cn[u] = 1; return; }
	int mid = (l+r)>>1;
	build(u<<1,l,mid),build(u<<1|1,mid+1,r);
	pushup(u);
}
void modify_min(int L,int R,int v,int u = 1,int l = 1,int r = n) {
	if(mx[u] <= v) return;
	if(L <= l && r <= R && se[u] < v) return pushtag(u, v);
	int mid = (l + r) >> 1;
	pushdown(u);
	if (L <= mid) modify_min(L,R,v,u<<1,l,mid);
	if (mid < R) modify_min(L,R,v,u<<1|1,mid+1,r);
	pushup(u);

}

long long query_sum(int L,int R,int u = 1,int l = 1,int r = n) {
	if (L <= l && r <= R) return sum[u];
	int mid = (l + r) >> 1;
	long long res = 0;
	pushdown(u);
	if (L <= mid) res += query_sum(L,R,u<<1,l,mid);
	if (mid < R) res += query_sum(L,R,u<<1|1,mid+1,r);
	return res;
}

void BFS(int m){
	int op,l,r,v;
	REP(i,1,m){
		cin>>op;
		if(op == 1){
			cin>>v;
			REP(i,1,n) a[i] = min(a[i],v);
		}
		else if(op == 2) REP(i,1,n) a[i] += i;
		else{
			ll ans = 0;
			cin>>l>>r;
			REP(i,l,r) ans += a[i];
			pr("%lld\n",ans);
		}
	}
	return;
}

signed main(){

	freopen("easy.in","r",stdin);
	freopen("easy.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int m;
	cin>>n>>m;
	REP(i,1,n) cin>>a[i];
	if(n <= 5050 && m <= 5050){ BFS(m);return 0; }
	build();
	int op,l,r,v;
	REP(i,1,m){
		cin>>op ;
		if(op == 1) cin>>v,modify_min(1,n,v);
		else cin>>l>>r,cout<<query_sum(l,r)<<'\n';
	}

	return 0;
}
