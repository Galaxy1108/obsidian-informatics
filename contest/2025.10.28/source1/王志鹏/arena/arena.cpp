#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a),i##i=(b);i<=i##i;i++)
#define ROF(i,a,b) for(int i=(a),i##i=(b);i>=i##i;i--)

template<typename T> inline void cmin(T &x, T y) {x = (x < y ? x : y);}
template<typename T> inline void cmax(T &x, T y) {x = (x > y ? x : y);}

using ll = long long;
using ull = unsigned long long;
using poly = std::vector<int>;


#define dbg(x) std::cerr << #x " = " << x << '\n'

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
#define wt(x) std::cout << x
#define pc(x) putchar(x)

const int N = 5e2 + 10;
const int mod = 998244353;

inline void chk(int &x) {x -= mod; x += x >> 31 & mod;}
inline int mll(int x, int y) {return (ll) x * y % mod;}
inline int inc(int x, int y) {chk(x += y); return x ;}
inline int dec(int x, int y) {return inc(x, mod - y);}

inline int ksm(int x, int y) {
  int ret = 1;
  for(; y; y >>= 1, x = mll(x, x))
    if(y & 1) ret = mll(ret, x);
  return ret;
}

inline int Inv(int x) {return ksm(x, mod - 2);}

int fc[N * N], fv[N * N], inv[N * N];
inline void pref(const int lim) {
  fc[0] = 1;
  for(int i = 1; i <= lim; i++)
    fc[i] = mll(fc[i - 1], i);
  
  fv[lim] = Inv(fc[lim]);
  for(int i = lim; i >= 1; i--)
    fv[i - 1] = mll(fv[i], i);
  
  for(int i = 1; i <= lim; i++) 
    inv[i] = mll(fv[i], fc[i - 1]);
  return ;
}

inline int binom(int n, int m) {
  if(n < m || n < 0 || m < 0) return 0;
  return mll(fc[n], mll(fv[m], fv[n - m]));
}

int n, s;
int f[N][N];

int dfs(int lim, int lst) {
  if(lim < lst) return 0;
  if(lst == 1) return 1;
  if(f[lim][lst]) return f[lim][lst];
  int ret = 0;
  for(int i = 0; i <= lst - 1; i++) {
    int tem = mll(ksm(lst - 1, i), binom(lst - 1, i));
    chk(ret += mll(tem, dfs(lim - lst + 1, lst - i)));
  }
  return f[lim][lst] = ret;
}

inline void solve() {
  n = rd, s = rd;
  pref(n + s);
  int ans = 0;
  for(int i = 1; i <= s; i++) 
    chk(ans += dfs(i, n));
  dbg(ksm(s, n));
  std::cout << dec(ksm(s, n), mll(ans, n)) << '\n';
  return ;
}

#define File(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)

int main() {
  File("arena");
  solve();
#ifdef LOCAL
  fprintf(stderr, "%f", (double) clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}
