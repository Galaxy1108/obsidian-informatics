#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define ull unsigned long long 
#define sz(a) ((int) a.size())
#define vi vector<int>
#define me(a, x) memset(a, x, sizeof(a))
using namespace std;
const int N = 305;
struct fenwt {
	int a[N + 1][N + 1];
	inline void add(int _x, int _y, int w) {
		for(int x = _x; x <= N; x += x & -x) 
			for(int y = _y; y <= N; y += y & -y) 
				a[x][y] += w;
	}
	inline int query(int _x, int _y) {
		int ret = 0;
		for(int x = _x; x; x -= x & -x) 
			for(int y = _y; y; y -= y & -y) 
				ret += a[x][y];
		return ret;
	}
	void clear() {
		me(a, 0);
	}
} ;
fenwt t1, t2, t3, t4;
int n, ns[N][N], cur;

ll wa, wb, xa, xb; // we need wa = wb = xa = xb = 0.
void mark(int x, int y, int w) {
	t1.add(x, y, w);
	t2.add(x, n - y + 1, w);
	t3.add(n - x + 1, n - y + 1, w);
	t4.add(n - x + 1, y, w);
	if(w < 0) ns[x][y] = ++cur;
}

bool nop; 
struct vec {
	int x, y, v1, v2, v3, v4, S;
} arr[N * N];
bool ok1, ok2, ok3, ok4;

bool chk(vec &a) {
//	cout << "NS = " << x << ' ' << y << ' ' << ns[x][y] << endl;
	int x = a.x, y = a.y;
	if(ns[x][y]) return false;
	int v1 = t1.query(x, y) - 1, v2 = t2.query(x - 1, n - y);
	int v3 = t3.query(n - x + 1, n - y + 1) - 1, v4 = t4.query(n - x, y - 1);
	a.v1 = v1;
	a.v2 = v2;
	a.v3 = v3;
	a.v4 = v4;
//	cout << v1 << ' ' << v2 << ' ' << v3 << ' ' << v4 << endl;
	if(wa < v1) return ok1 = 1, false;
	if(wb < v2) return ok2 = 1, false;
	if(xa < v3) return ok3 = 1, false;
	if(xb < v4) return ok4 = 1, false;
	if(nop) return false;
//	cout << "pb " << x << ' ' << y << " : " << v2 << endl;
	wa -= v1;
	wb -= v2;
	xa -= v3;
	xb -= v4;
	mark(x, y, -1);
	return true;
}
ll x, y;

int tot;

mt19937 orz;

void Main() {
	me(arr, 0);
	ok1 = ok2 = ok3 = ok4 = 0;
	t1.clear(), t2.clear(), t3.clear(), t4.clear(), me(ns, 0), cur = tot = 0;
	cin >> n >> x >> y;
	ll t = (ll) n * (n - 1) / 2;
	t *= t;
	if(x % 2 != (y + t) % 2) return cout << "NO\n", void();
	if(abs(x - y) > t) return cout << "NO\n", void();
	ll lim = (ll) n * n * (n * n - 1);
	if(x + y > lim - t) return cout << "NO\n", void();
	if(x + y < t) return cout << "NO\n", void();
	wa = (x + y - t) / 2;
	wb = (x + t - y) / 2;
	xa = lim / 2 - t - wa;
	xb = t - wb;
	L(i, 1, n) L(j, 1, n) mark(i, j, 1); 
	L(i, 1, n) L(j, 1, n) ++tot, arr[tot].x = i, arr[tot].y = j;
	int l = 1, r = tot, count = 0;
	while(l <= tot) {
		count = (ll) ok1 + ok2 + ok3 + ok4;
		ll s = 0;
		int ql = l, qr = r, op = 0, au = 0;
		for(; ql <= qr; op ^= 1) {
			if(count) op = 1;
			++s;
			if(op) {
				if(chk(arr[ql])) swap(arr[ql], arr[l]), au = 1;
				++ql;
			} else {
				if(chk(arr[qr])) swap(arr[ql], arr[r]), au = 1;
				--qr;
			}
			if(au) break;
		}
		if(!au) assert(false);
		while(ns[arr[l].x][arr[l].y]) ++l;
		while(ns[arr[r].x][arr[r].y]) --r;
		if(count != (ll) ok1 + ok2 + ok3 + ok4 || s >= 1145) {
			count = (ll) ok1 + ok2 + ok3 + ok4;
			nop = 1; 
			L(i, l, r) {
				chk(arr[i]);
				arr[i].S = 0;
				if(ok1) arr[i].S += arr[i].v1;
				if(ok2) arr[i].S += arr[i].v2;
				if(ok3) arr[i].S += arr[i].v3;
				if(ok4) arr[i].S += arr[i].v4;
			}
			nop = 0;
			sort(arr + l + 1, arr + r + 1, [&] (vec a, vec b) {
				return a.S < b.S;
			});
		}
	}
	cout << "YES\n";
	L(i, 1, n) {
		L(j, 1, n) cout << ns[i][j] << ' ';
		cout << '\n';
	}
}
int main() {
	freopen("matrixcascade.in", "r", stdin);
	freopen("matrixcascade.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t ;
	while(t--) Main();
	return 0;
}