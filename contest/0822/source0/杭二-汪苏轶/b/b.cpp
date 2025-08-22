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

const int maxn = 2010;

int n, a[maxn][maxn], inq[maxn][2];
ll dis[maxn][2];

int main() {
  freopen("b.in", "r", stdin);
  freopen("b.out", "w", stdout);
  cin.tie(nullptr) -> ios::sync_with_stdio(false);
  cin >> n;
  rep (i, 1, n) rep (j, i + 1, n) cin >> a[i][j], a[j][i] = a[i][j];
  int mn = 1e9;
  rep (i, 1, n) rep (j, i + 1, n) chkmn(mn, a[i][j]);
  rep (i, 1, n) rep (j, 1, n) if (i != j) a[i][j] -= mn;
  int s = 0, t = 0;
  rep (i, 1, n) rep (j, i + 1, n) if (!a[i][j]) s = i, t = j;
  rep (i, 1, n) rep (j, 0, 1) dis[i][j] = 1e18;
  dis[s][1] = dis[t][1] = 0, inq[s][1] = inq[t][1] = 1;
  while (true) {
    ll mn = 1e18;
    int u = -1, k = -1;
    rep (i, 1, n) rep (j, 0, 1) if (dis[i][j] < mn && inq[i][j]) {
      mn = dis[i][j], u = i, k = j;
    }
    if (u == -1) break;
    inq[u][k] = 0;
    rep (v, 1, n) if (u != v) {
      if (k) {
        if (dis[u][k] < dis[v][0]) {
          dis[v][0] = dis[u][k];
          inq[v][0] = 1;
        }
        if (dis[u][k] + a[u][v] < dis[v][1]) {
          dis[v][1] = dis[u][k] + a[u][v];
          inq[v][1] = 1;
        }
      } else {
        if (dis[u][k] + 2 * a[u][v] < dis[v][1]) {
          dis[v][1] = dis[u][k] + 2 * a[u][v];
          inq[v][1] = 1;
        }
      }
    }
  }
  rep (i, 1, n) cout << dis[i][1] + 1ll * mn * (n - 1) << '\n';
}