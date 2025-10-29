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
const ll INF = 1e18;

int n;
int a[N];
ll f[N][5];

inline void solve() {
  n = rd;
  FOR(i, 1, n) a[i] = rd;
  FOR(i, 0, n) FOR(j, 0, 4) f[i][j] = INF;
  f[0][0] = 0;
  FOR(i, 1, n) {
    
    ll now = f[i - 1][0];
    f[i][0] = now + a[i];
    cmin(now, f[i - 1][1]);
    f[i][1] = now + (a[i] & 1);
    cmin(now, f[i - 1][2]);
    f[i][2] = now + !(a[i] & 1);
    cmin(now, f[i - 1][3]);
    f[i][3] = min(f[i - 1][2], f[i - 1][3]) + (a[i] & 1);
    cmin(now, f[i - 1][4]);
    f[i][4] = now + a[i];
    if(a[i] == 0) {
      f[i][0] = f[i - 1][0] + a[i];
      f[i][1]++;
      f[i][2] += 2;
      f[i][3]++;
      f[i][4] = min(f[i - 1][1], min(f[i - 1][2], min(f[i - 1][3], f[i - 1][4]))) + a[i];
      continue;
    } 
  }
  ll ans = f[n][0];
  cmin(ans, min(f[n][1], f[n][2]));
  cmin(ans, min(f[n][3], f[n][4]));
  cout << ans << '\n';
  
  
  return ;
}

#define File(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)

int main() {
  File("walk");
  solve();
  
#ifdef LOCAL
  fprintf(stderr, "%f", (double) clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}
