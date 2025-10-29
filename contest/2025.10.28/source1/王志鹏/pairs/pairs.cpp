#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i=(a),i##i=(b);i<=i##i;i++)
#define ROF(i,a,b) for(int i=(a),i##i=(b);i>=i##i;i--)

template<typename T> inline void cmin(T &x, T y) {x = (x < y ? x : y);}
template<typename T> inline void cmax(T &x, T y) {x = (x > y ? x : y);}

using ll = long long;
using ull = unsigned long long;
using poly = vector<int>;

ostream &operator << (ostream &ou, poly F) {
  FOR(i, 0, F.size() - 1) ou << " {"[i == 0] << F[i] << ",}"[i == ii];
  return ou;
}

#ifdef LOCAL 
#define dbg(x) cerr << #x " = " << x << '\n'
#else
#define dbg(x)
#endif

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

const int N = 210;

int n, mod;
int fc[N], C[N][N], f[N];
poly H[N], F[N];

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

inline void pref(const int lim) {
  fc[0] = 1;
  for(int i = 1; i <= lim; i++) 
    fc[i] = mll(fc[i - 1], i);
  
  for(int i = 0, j; i <= lim; i++) 
    for(*C[i] = j = 1; j <= i; j++) 
      C[i][j] = inc(C[i - 1][j], C[i - 1][j - 1]);
  return ;
}

void Mul(poly F, poly G, poly &H) {
  int n = F.size() + G.size() - 1;
  H.resize(n);
  FOR(i, 0, F.size() - 1) FOR(j, 0, G.size() - 1) 
    chk(H[i + j] += mll(F[i], G[j]));
  return ;
}

inline void solve() {
  n = rd, mod = rd;
  pref(n + 10);
  poly G;
  G.push_back(1), F[1] = G;
  FOR(i, 2, n - 1) {
    G.push_back(1);
    Mul(F[i - 1], G, F[i]);
  }
  FOR(i, 3, n - 1) H[i] = F[i];
  FOR(i, 3, n - 1) FOR(j, 1, H[i].size() - 1) chk(H[i][j] += H[i][j - 1]);
//  FOR(i, 1, n - 1) cerr << "F[" << i << "] = " << F[i] << '\n';
//  FOR(i, 1, n - 1) cerr << "H[" << i << "] = " << H[i] << '\n';
  FOR(i, 4, n) {
    poly fi = F[i - 1], hi = H[i - 1];
    FOR(s, 1, i - 1) {
      int tem = 0;
      FOR(d, 0, fi.size() - 1) {
        if(d - s < 1) continue;
        chk(tem += mll(fi[d], hi[d - s - 1]));
      }
      chk(f[i] += mll(tem, i - s));
//      fprintf(stderr, "%d , %d , %d = %d\n", i, j, k, f[i]);
    }
  }
//  FOR(i, 1, n) fprintf(stderr, "f[%d] = %d\n", i, f[i]);
  int ans = 0;
  FOR(i, 0, n) chk(ans += mll(mll(C[n][i], fc[i]), f[n - i]));
  dbg(ans);
  cout << ans << '\n';
  return ;
}

#define File(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)

int main() {
  File("pairs");
  solve();
#ifdef LOCAL
  fprintf(stderr, "%f", (double) clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}
