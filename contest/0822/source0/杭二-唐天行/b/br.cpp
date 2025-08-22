#include <bits/stdc++.h>

using namespace std;

// #define LOCK_GETCHAR
// #define USE_INT_128

#if __cplusplus < 201400
#warning "Please use c++14 or higher."
#define CONSTEXPR_FUNC
#define ENABLE_IF_INT
#else
#define CONSTEXPR_FUNC constexpr
#define ENABLE_IF_INT , enable_if_t<_is_integer<T>, int> = 0
template <class T> constexpr bool _is_integer = numeric_limits<T>::is_integer;
template <> constexpr bool _is_integer<bool> = false;
template <> constexpr bool _is_integer<char> = false;
#ifdef USE_INT_128
template <> constexpr bool _is_integer<__int128> = true;
template <> constexpr bool _is_integer<__uint128_t> = true;
#endif
#endif

#if !defined(_WIN32) && !defined(LOCK_GETCHAR)
#define getchar getchar_unlocked
#endif

#define il inline
#define mkp make_pair
#define fi first
#define se second
#define _loop_i_t(j, k) make_signed_t<decltype((j) - (k))>
#define For(i, j, k) for (_loop_i_t(j, k) i = (j); i <= (k); ++i) // NOLINT
#define ForDown(i, j, k)                                                       \
  for (_loop_i_t(j, k) i = (j); i >= decltype(i)(k); --i) // NOLINT
#define eb emplace_back
#ifndef ONLINE_JUDGE
#define FileIO(filename)                                                       \
  freopen(filename ".in", "r", stdin);                                         \
  freopen(filename ".out", "w", stdout)
#else
#define FileIO(filename) void(0)
#endif

using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using db = double;
using ldb = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#ifdef USE_INT_128
using lll = __int128_t;
using ulll = __uint128_t;
#endif

// clang-format off
CONSTEXPR_FUNC il ll qpow(ll x, ull y, ll mod){ ll ans = 1; x %= mod; while (y) { if (y & 1) (ans *= x) %= mod; (x *= x) %= mod; y >>= 1; } return ans; }
template<typename T> CONSTEXPR_FUNC il void cmin(T & x, const T &y){ x = min(x, y); }
template<typename T> CONSTEXPR_FUNC il void cmax(T & x, const T &y){ x = max(x, y); }
template<typename T ENABLE_IF_INT> il void read(T &x){ x = 0; int f = 1; int c = getchar(); while (!isdigit(c)) { if (c == '-') f = -1; c = getchar(); } while (isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); } x *= f; }
template<typename T, typename ... Args> il void read(T &x, Args &... y){ read(x), read(y...); }
// clang-format on

// File head end

namespace {
constexpr ll MAXN = 2005;
int n, w[MAXN][MAXN], id[MAXN];
ll f[MAXN];
il void Main() {
  read(n);
  For(i, 1, n - 1) For(j, i + 1, n) read(w[i][j]), w[j][i] = w[i][j];
  fill(f + 1, f + 1 + n, ll(1e18) + 5);
  iota(id + 1, id + 1 + n, 1);
  do {
    ll ans = 0;
    int v = 1e9 + 5;
    For(i, 2, n) cmin(v, w[id[i - 1]][id[i]]), ans += v;
    cmin(f[id[1]], ans);
  } while (next_permutation(id + 1, id + 1 + n));
  For(i, 1, n) cout << f[i] << '\n';
}
} // namespace

signed main() { return Main(), 0; }
