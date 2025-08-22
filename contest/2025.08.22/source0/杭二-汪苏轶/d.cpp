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

const int maxn = 100010;

int n, q, p[maxn];

void solve(int l, int r) {
  if (l == r) return cout << "0 " << p[l] << " 1\n", void();
  int c = 1, mxd = 0;
  rep (i, l, r - 1) chkmx(mxd, p[i + 1] - p[i]);
  while (true) {
    ll la = max(0ll, 1ll * (mxd - 1) * c), ra = la + 2 * c - 1;
    for (ll a = la; a <= ra; a++) {
      ll mx = -1e18, mn = 1e18;
      rep (i, l, r) {
        chkmx(mx, 1ll * p[i] * c - i * a);
        chkmn(mn, 1ll * p[i] * c - i * a);
      }
      if (mx > mn + c - 1) continue;
      cout << a << " " << mx + a * l << " " << c << '\n';
      return;
    }
    c++;
  }
}

void work() {
  cin >> n;
  rep (i, 1, n) cin >> p[i];
  cin >> q;
  rep (i, 1, q) {
    int l, r;
    cin >> l >> r;
    solve(l, r);
  }
}

int main() {
  freopen("d.in", "r", stdin);
  freopen("d.out", "w", stdout);
  cin.tie(nullptr) -> ios::sync_with_stdio(false);
  int t; cin >> t;
  while (t--) work();
}
