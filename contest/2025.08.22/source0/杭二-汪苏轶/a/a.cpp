#include <bits/stdc++.h>

#define rep(i, j, k) for (int i = (j); i <= (k); ++i)
#define per(i, j, k) for (int i = (j); i >= (k); --i)
#define SZ(v) int((v).size())
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second
using ll = long long;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;

template<class T>inline void chkmn(T &x, T y) { if (y < x) x = y; }
template<class T>inline void chkmx(T &x, T y) { if (y > x) x = y; }

using namespace std;

const int maxn = 10000010;

int n, m, mod, f[maxn], g[maxn], of[maxn], og[maxn];

__int128 mu;
namespace barrett {
  inline ll reduce(ll x) {
    ll r = x - (mu * x >> 64) * mod;
    return r >= mod ? r - mod : r;
  }
  inline void setmod(ll mod) {
    mu = -1ull / mod;
  }
}
using namespace barrett;

int add(int x, int y) { return (x + y >= mod) ? x + y - mod : x + y; }
int sub(int x, int y) { return (x - y < 0) ? x - y + mod : x - y; }
void Add(int &x, int y) { x = (x + y >= mod) ? x + y - mod : x + y; }
void Sub(int &x, int y) { x = (x - y < 0) ? x - y + mod : x - y; }

int main() {
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
  cin.tie(nullptr) -> ios::sync_with_stdio(false);
  cin >> n >> m >> mod, setmod(mod);
  rep (i, 1, m) f[i] = m - i + 1, g[i] = i;
  per (i, m, 1) Add(f[i], f[i + 1]);
  rep (i, 1, m) Add(g[i], g[i - 1]);
  rep (i, 2, n) {
    rep (j, 1, m) of[j] = f[j], og[j] = g[j], f[j] = g[j] = 0;
    rep (j, 1, m) f[j] = reduce(1ll * sub(of[1], og[j - 1]) * (m - j + 1));
    rep (j, 1, m) g[j] = reduce(1ll * sub(of[1], of[j + 1]) * j);
    int psum = 0, ssum = 0;
    rep (j, 1, m) Sub(g[j], psum), Add(psum, og[j]);
    per (j, m, 1) Sub(f[j], ssum), Add(ssum, of[j]);
    per (i, m, 1) Add(f[i], f[i + 1]);
    rep (i, 1, m) Add(g[i], g[i - 1]);
  }
  cout << f[1] << '\n';
}