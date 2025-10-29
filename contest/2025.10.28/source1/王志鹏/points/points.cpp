#include <bits/stdc++.h>

using namespace std; 

#define FOR(i,a,b) for(int i=(a),i##i=(b);i<=i##i;i++)
#define ROF(i,a,b) for(int i=(a),i##i=(b);i>=i##i;i--)

template<typename T> inline void cmin(T &x, T y) {x = (x < y ? x : y);}
template<typename T> inline void cmax(T &x, T y) {x = (x > y ? x : y);}

using ll = long long;
using ull = unsigned long long;
using poly = vector<int>;

#define dbg(x) cerr << #x " = " << x << '\n'

namespace fastio {
#define gc (wo==ow&&(ow=(wo=buf)+fread(buf,1,100000,stdin),wo==ow)?EOF:*wo++)
  char buf[100000], *wo(buf), *ow(buf);
  inline ll read() {
    ll x = 0;
    bool f = true;
    char ch = gc;
    while(!isdigit(ch)) {
      if(ch == '-') f = false;
      ch = gc;
    }
    while(isdigit(ch)) {
      x = (x << 1) + (x << 3) + (ch ^ 48);
      ch = gc;
    }
    return f ? x : -x;
  }
#undef gc
}
#define rd fastio::read()

const int N = 2e5 + 10;
const int INF = 2e9 + 10;

int n, m, tot;
int a[N];
struct node {int l, r;} lin[N];

inline void solve() {
  n = rd, m = rd;
  for(int i = 1; i <= n; i++) a[i] = rd;
  FOR(i, 1, m) lin[i].l = rd, lin[i].r = rd;
  sort(a + 1, a + 1 + n);
  FOR(i, 1, m) {
    int pos = lower_bound(a + 1, a + 1 + n, lin[i].l) - a;
    if(a[pos] > lin[i].r) lin[++tot] = lin[i];
  }
  ll ans = 0;
  a[0] = -INF, a[n + 1] = INF;
  FOR(i, 1, tot) {
    int pos = lower_bound(a + 1, a + 1 + n, lin[i].l) - a;
    ans += min(abs(a[pos] - lin[i].r), abs(a[pos - 1] - lin[i].l));
  }
  cout << ans << '\n';
  return ;
}

#define File(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)

int main() {
  File("points");
  solve();
  
#ifdef LOCAL
  fprintf(stderr, "%f", (double) clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}  
