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
constexpr ll MAXN = 1e7 + 5;
int n, m;
ll p, f[2][MAXN], g[2][MAXN];
il void Main() {
  FileIO("a");
  read(n, m, p);
  For(i, 1, m) { f[1][i] = m - i + 1, g[1][i] = i; }
  For(i, 2, n) {
    int cur = i & 1, pre = cur ^ 1;
    ll sum = 0, sum2 = 0, sum3 = 0;
    For(j, 1, m)(sum += f[pre][j]) %= p;
    For(j, 1, m) {
      (f[cur][j] = sum * (m - j + 1)) %= p, (g[cur][j] = sum * j) %= p;
    }
    sum = sum2 = 0;
    ForDown(j, m, 1) {
      (sum += p - f[pre][j + 1]) %= p;
      (sum2 += f[pre][j]) %= p;
      (sum3 += f[pre][j] * j) %= p;
      (g[cur][j] += sum * j) %= p;
      (f[cur][j] += (p + sum2 * j % p - sum3)) %= p;
    }
    sum = sum2 = sum3 = 0;
    For(j, 1, m) {
      (sum += p - g[pre][j - 1]) %= p;
      (sum2 += g[pre][j]) %= p;
      (sum3 += g[pre][j] * j) %= p;
      (f[cur][j] += sum * (m - j + 1)) %= p;
      (g[cur][j] += (p + sum3 - sum2 * j % p)) %= p;
    }
  }
  ll ans = 0;
  For(i, 1, m)(ans += f[n & 1][i]) %= p;
  cout << ans << '\n';
}
} // namespace

signed main() { return Main(), 0; }
