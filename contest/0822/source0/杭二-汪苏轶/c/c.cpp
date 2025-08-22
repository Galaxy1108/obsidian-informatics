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

const int maxn = 5010;

int n, seed, a[maxn][maxn], b[maxn << 1][maxn], fir[maxn];
bool vis[maxn << 1][maxn];

int main() {
  freopen("c.in", "r", stdin);
  freopen("c.out", "w", stdout);
  cin.tie(nullptr) -> ios::sync_with_stdio(false);
  cin >> n >> seed;
  if (!seed) {
    rep (i, 1, n) rep (j, 1, n + 1) cin >> a[i][j];
  } else {
    mt19937 rng(seed);
    rep (i, 1, n) rep (j, 1, n + 1) a[i][j] = j, swap(a[i][j], a[i][rng() % j + 1]);
  }
  rep (i, 1, n) rep (j, 1, n + 1) b[i][a[i][j]] = j;
  rep (i, 1, n) rep (j, 1, n + 1) b[i + n][j] = b[i][j];
  rep (i, 1, n + 1) fir[i] = 2 * n;
  per (s, 2 * n - 1, 1) {
    int lst = s - 1;
    rep (i, 1, n + 1) {
      int pos = fir[b[s][i]] - 1;
      chkmn(pos, s + n - 1);
      if (pos > lst) {
        chkmn(fir[b[s][i]], lst + 1);
        rep (j, lst + 1, pos) vis[j][b[s][i]] = 1;
        lst = pos;
      }
    }
  }
  rep (s, 1, n) {
    int t = s + n - 1, ans = 1;
    while (vis[t][ans]) ans++;
    cout << ans << " \n"[s == n];
  }
}