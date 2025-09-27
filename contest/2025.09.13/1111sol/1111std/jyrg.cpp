#include <bits/stdc++.h>
#define int long long
#define R(i, a, b) for (auto i = (a); i < (b); ++i)
#define L(i, a, b) for (auto i = (b) - 1; i >= (a); --i)
#define N(a) int((a).size())
#define V(a) (a).begin(), (a).end()
#define P make_pair
#define spc << ' '
#define ntr << '\n'
#define X(a) cerr << #a << " = " << a
#define T() cerr << "TIME = " << double(clock() - T0) / CLOCKS_PER_SEC
using namespace std;
using i64 = long long;
clock_t T0 = clock();
template<typename tp>
ostream &operator<<(ostream &ost, const pair<tp, tp> &a) {
	for (tp i = a.first; i != a.second; ++i) ost << *i spc;
	return ost;
}
constexpr int xint = 1ll << 62;
int nT, T;
constexpr int xn = 2000000 + 7;
int n, a[xn], b[xn];
constexpr int xp = 4000000 + 7;
int p = 1, seg_n, ls[xp], rs[xp];
int f[xp], s[xp];
int rt;
void pushup(int u) {
	s[u] = s[ls[u]] + s[rs[u]];
	f[u] = max(f[ls[u]] + 2 * s[rs[u]], f[rs[u]]);
}
void build(int &u, int l = 0, int r = seg_n) {
	u = p++;
	s[u] = 0;
	f[u] = -xint;
	if (r - l == 1) return;
	int mid = (l + r) / 2;
	build(ls[u], l, mid);
	build(rs[u], mid, r);
}
void fix(int i, int u, int l = 0, int r = seg_n) {
	if (r - l == 1) {
		s[u] = 1;
		f[u] = b[i];
		return;
	}
	int mid = (l + r) / 2;
	if (i < mid) fix(i, ls[u], l, mid); else fix(i, rs[u], mid, r);
	pushup(u);
}
int sum(int y, int x, int u, int l = 0, int r = seg_n) {
	if (l >= y) return -xint;
	if (r <= y) return f[u] + 2 * x;
	int mid = (l + r) / 2;
	return max(sum(y, x + s[rs[u]], ls[u], l, mid), sum(y, x, rs[u], mid, r));
}
int resolveT() {
	cin >> n;
	R(i, 0, n) cin >> a[i];
	R(i, 0, n) b[i] = a[i] -= i;
	sort(b, b + n);
	R(i, 0, n - 1) if (b[i] == b[i + 1]) return -1;
	seg_n = n;
	build(rt);
	int mx = 0;
	R(i, 0, n) {
		int pos = lower_bound(b, b + n, a[i]) - b;
		mx = max(mx, sum(pos, 0, rt) + 1 + a[i]);
		fix(pos, rt);
	}
	return mx;
}
void solveT() {
	cout << resolveT() ntr;
}
signed main() {
	freopen("jyrg.in", "r", stdin);
	freopen("jyrg.out", "w", stdout);
	cerr << fixed << setprecision(3);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> nT;
//	nT = 1;
	for (; T < nT; ++T) solveT();
}
