#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int > 
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long
#define ld __float128
using namespace std;
const int N = (1 << 19) + 1, mod = 998244353;
int Num, n, q, a[N], pw[N], ns, lg[N];

int mx[N];
ll sum[N];

ll mn[N][20], fs[N][20];
int fns[N][20];

void upd(int x) {
	mx[x] = a[mx[x << 1]] < a[mx[x << 1 | 1]] ? mx[x << 1 | 1] : mx[x << 1];
	sum[x] = sum[x << 1] + sum[x << 1 | 1];
	L(i, 0, 19) 
		mn[x][i] = min(mn[x << 1][i] + fs[x << 1 | 1][i], mn[x << 1 | 1][i]), 
		fs[x][i] = fs[x << 1][i] + fs[x << 1 | 1][i], 
		fns[x][i] = (fns[x << 1][i] + fns[x << 1 | 1][i]) % mod;
}

void wap(int x, int p) {
	mx[x] = p, sum[x] = a[p];
	int LG = lg[a[p]];
	me(fs[x], 0), me(mn[x], 0x3f), me(fns[x], 0);
	L(i, LG + 1, 19) fs[x][i] = a[p], fns[x][i] = pw[p];
	mn[x][LG] = a[p];
}

void mark(int x, int L, int R, int p) {
	if(L == R) return wap(x, p), void();
	int mid = (L + R) >> 1;
	p <= mid ? mark(x << 1, L, mid, p) : mark(x << 1 | 1, mid + 1, R, p); upd(x);
}

void build(int x, int L, int R) {
	if(L == R) return wap(x, L), void();
	int mid = (L + R) >> 1;
	build(x << 1, L, mid), build(x << 1 | 1, mid + 1, R); upd(x);
}

ll ms;
int getcur(int x, int L, int R, int s) {
	if(L == R) return L;
	int mid = (L + R) >> 1;
	if(sum[x << 1] >= s) return getcur(x << 1, L, mid, s);
	else return getcur(x << 1 | 1, mid + 1, R, s - sum[x << 1]);
} 

ll getsum(int x, int L, int R, int l, int r) {
	if(l <= L && R <= r) return sum[x];
	int mid = (L + R) >> 1;
	ll s = 0;
	if(l <= mid) s += getsum(x << 1, L, mid, l, r);
	if(r > mid) s += getsum(x << 1 | 1, mid + 1, R, l, r);
	return s;
}

int cp;
ll rnt;
void gm(int x, int L, int R, int l, int r) {
	rnt += 1;
	if(L == R) {
		if(cp >= a[L]) cp -= a[L], (ns += pw[L]) %= mod;
		return ;
	}
	if(!cp) return;
	int mid = (L + R) >> 1;
	if(l <= L && R <= r) {
		int d = lg[cp], less = cp - (1 << d);
		if(mn[x][d] > cp && fs[x][d] <= less) {
			cp -= fs[x][d];
			(ns += fns[x][d]) %= mod;
			return ;
		}
		gm(x << 1 | 1, mid + 1, R, l, r);
		gm(x << 1, L, mid, l, r);
		assert(cp < (1 << d));
		return ;
	}
	if(r > mid) gm(x << 1 | 1, mid + 1, R, l, r);
	if(l <= mid) gm(x << 1, L, mid, l, r);
}

int calc() {
	int mxp = mx[1];
	int s = 0, cur = getcur(1, 1, n, a[mxp]);
	s = getsum(1, 1, n, 1, cur) - a[mxp], cp = s;
	int qwq = (pw[cur + 1] + mod - 2) % mod;
	rnt = 0;
	ns = 0, gm(1, 1, n, 1, cur);
//	cerr << rnt << endl;
	ns = (qwq + mod - ns) % mod;
	return ns;
}
int main() {
//	return system("fc imperishable2.ans imperishable.out"), 0;
	freopen("imperishable.in", "r", stdin);
	freopen("imperishable.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> Num >> n;
	pw[0] = 1;
	L(i, 1, n + 1) pw[i] = (ll) pw[i - 1] * 2 % mod; 
	L(i, 0, 17) 
		L(j, 0, (1 << i) - 1) 
			lg[(1 << i) + j] = i;
	L(i, 1, n) 
		cin >> a[i]; 
	build(1, 1, n);
	cin >> q;
	cout << calc() << '\n';
	while(q--) {
		int x, y;
		cin >> x >> y ;
		a[x] = y, mark(1, 1, n, x), cout << calc() << '\n';
	}
	return 0;
}