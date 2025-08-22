// author : georgeyucjr
#include <bits/stdc++.h>

using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;
using arr3 = std ::array<int, 3>;
using arr4 = std ::array<int, 4>;
using pii = std ::pair<int, int>;

#define ALL(vc) std ::begin(vc), std ::end(vc)
#define rep(i, f, t, ...) for (std ::decay<decltype(f + t)>::type i = f, _END_##i = t, ##__VA_ARGS__; i <= _END_##i; ++i)
#define per(i, f, t, ...) for (std ::decay<decltype(f + t)>::type i = f, _END_##i = t, ##__VA_ARGS__; i >= _END_##i; --i)
#define eb emplace_back
#define pb push_back
#define mkp make_pair
#define FILEIO(filename) freopen(filename ".in", "r", stdin), freopen(filename ".out", "w", stdout)
template <class T, class U> inline T ceil(T &&x, U &&y) { return (x > 0 ? (x + y - 1) / y : x / y); }
template <class T, class U> inline T floor(T &&x, U &&y) { return (x > 0 ? x / y : (x - y + 1) / y); }
template <class T, class U> inline T divmod(T &&x, U &&y) { auto &&q = floor(x, y); return mkp(q, x - q * y); }
template <class T> constexpr static T inf = std ::numeric_limits<T>::max() >> 1;
template <class T> inline int SZ(T &&x) { return x.size(); }
template <typename T> inline T Abs(const T &x) { return x < 0 ? -x : x; }
template <typename T> inline T sqr(const T &x) { return x * x; }
template <typename T> inline T Max(const T &x) { return x; }
template <typename T> inline T Min(const T &x) { return x; }
template <typename T, typename U, typename... Args> inline T Max(const T &x, const U &y, const Args &...args) { return x < y ? Max(y, args...) : Max(x, args...); }
template <typename T, typename U, typename... Args> inline T Min(const T &x, const U &y, const Args &...args) { return x < y ? Min(x, args...) : Min(y, args...); }
template <typename T, typename... Args> inline void chkmax(T &d, const Args &...x) { d = Max(d, x...); }
template <typename T, typename... Args> inline void chkmin(T &d, const Args &...x) { d = Min(d, x...); }

using namespace std;

#ifdef georgeyucjr
#include <georgeyucjr/debug.h>
#else
#define dbg(...) 36
#endif

namespace easy_IO {
# ifndef LOCAL
constexpr std::size_t BUFSIZE = 1 << 20; char ibuf[BUFSIZE], *iS, *iT;
#define getchar() (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, BUFSIZE, stdin), (iS == iT ? EOF : *iS++)) : *iS++)
# endif
inline void read(char &c) { c = getchar(); } inline void read(string &str, bool is_move = false) { if (is_move) str += ' '; char c = getchar(); while (c != ' ' && c != '\n') str += c, c = getchar(); }
template <typename T> inline void read(T &x, bool is_unsigned = false) { x = 0; char ch = getchar(); if (is_unsigned) { while (ch < '0' || ch > '9') ch = getchar(); while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar ( ); } else { T _read_flag = (T)(1); while (ch < '0' || ch > '9') _read_flag = ch == '-' ? -1 : 1, ch = getchar(); while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar ( ); x *= _read_flag; } return void(); }
template <typename T> inline void read(vector<T> &v) { for (T &i : v) read(v); } template <typename T, typename... Args> inline void read(T &x, Args&... args) { read(x), read(args...); } template <typename T, typename U> inline void read(pair<T, U> &p) { read(p.first, p.second); }
template <typename T, typename U, typename V> inline void read(tuple<T, U, V> &t) { read(get<0>(t), get<1>(t), get<2>(t)); }
# ifndef LOCAL
char obuf[BUFSIZE], *oS = obuf, *oT = oS + BUFSIZE - 1; inline void flush() { fwrite(obuf, 1, oS - obuf, stdout), oS = obuf; } 
# define putchar(x) (*oS++ = x, ( oS == oT ) ? flush() : void())
# else
# define flush() 36
# endif
inline void write ( char c ) { putchar ( c ); }  inline void write ( string s ) { for (char c : s) putchar ( c ); }
template <typename T> inline void write(T x, bool is_unsigned = false) { if (!is_unsigned) if (x < 0) x = -x, putchar ('-'); if (x > 9) write(x / 10); putchar (x % 10 ^ '0'); }
template <typename T> inline void writeln(T x) { write (x), putchar('\n'); } 
template <typename T> inline void writespc(T x) { write (x), putchar(' '); }
template <typename T, typename ... Args> inline void write(T x, Args ... args) { write(x), write(args...); }
template <typename T, typename ... Args> inline void writeln(T x, Args ... args) { write(x), putchar(' '), write(args...), putchar('\n'); }
template <typename T, typename ... Args> inline void writespc(T x, Args ... args) { write(x), putchar(' '), write(args...), putchar(' '); }
template <typename T> inline void writeall(T x, char blank = ' ', bool Endl = true) { std::for_each(std::begin(x), std::end(x), [&](auto x) { write(x), putchar(' '); }); if (Endl) putchar('\n'); }
} // namespace easy_IO
using namespace easy_IO;

# define int long long

constexpr int N = 2005;

int n, m, rt = 0, w[N][N];

namespace Sub1 {
	int dsu_fa[N], dis[N], mn[N];
	vector<pii> G[N];
	int find(int x) {
		return dsu_fa[x] == x ? dsu_fa[x] : dsu_fa[x] = find(dsu_fa[x]);
	}
	bool same(int u, int v) {
		return find(u) == find(v);
	}
	bool merge(int u, int v) {
		int du = find(u), dv = find (v);
		if (du == dv) return false;
		else return dsu_fa[du] = dv, true;
	}
	int fa[N], dep[N];
	void dfs(int u, int _f) {
		fa[u] = _f, dep[u] = dep[_f] + 1;
		for (auto [v, w] : G[u]) if (v != _f) dfs(v, u), dis[v] = dis[u] + w, chkmin(mn[v], w);
	}
	int LCA(int u, int v){ 
		if (dep[u] < dep[v]) swap(u, v);
		while(dep[u] != dep[v]) u = fa[u];
		if (u == v) return u;
		while(u != v) u = fa[u], v = fa[v];
		assert(u == v);
		return u;
	}
	int work(vector<pii> es) {
		assert(SZ(es) == n - 1);
		// check connect
		iota(dsu_fa + 1, dsu_fa + n + 1, 1);
		fill(fa + 1, fa + n + 1, 0);
		fill(dep + 1, dep + n + 1, 0);
		fill(dis + 1, dis + n + 1, 0);
		fill(mn + 1, mn + n + 1, inf<int>);
		for (auto &&[u, v] : es) 
			if (!merge(u, v)) return inf<int>;
		// calc val
		rep(i, 1, n)
		G[i].clear();
		for (auto &&[u, v] : es) G[u].eb(v, w[u][v]), G[v].eb(u, w[u][v]);
		dfs(1, 0);
		int sum = 0;
		rep(i, 1, n) if (i != rt) sum += mn[i];
		writeln(sum);
	}
}  // namespace Sub1

signed main() {
	FILEIO("b");
	read(n);
	vector<pii> es;
	rep(i, 1, n) rep(j, i + 1, n) read(w[i][j]), w[j][i] = w[i][j], ++m, es.eb(j, i);
	if (n <= 8) {
		int ans = inf<int>;
		rep(i, 1, n) {
			rt = i;
			per(state, (1 << m) - 1, 0) {
				if (__builtin_popcount(state) != n - 1) continue;
				vector<pii> ce;
				rep(t, 0, m - 1) if (state & (1 << t)) ce.pb(es[t]);
				chkmin(ans,Sub1:: work(ce));
			}
		}
		assert(ans < (int)1e9);
		writeln(ans);
	}

#if defined(LOCAL) && !defined(CPH)
  std::cerr << "Spend Time : " << clock() * 1. / CLOCKS_PER_SEC * 1e3 << " ms \n";
#endif
  return flush(), 0;
}