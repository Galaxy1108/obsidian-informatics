#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 10000005;
int n, m, MOD, F[MAXN], G[MAXN], S[MAXN], Ans;
inline int add(int x, int y){return (x += y) >= MOD? x - MOD: x;}
inline int sub(int x, int y){return (x -= y) <    0? x + MOD: x;}
inline int mul(int x, int y){return (int64_t)x * y % MOD;}
int main(){
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> m >> MOD;
  for(int i = 1; i <= m; i++) F[i] = i;
  while(--n){
    int sum = 0;
    for(int i = 1; i <= m; i++) S[i] = add(S[i - 1], F[i]);
    for(int i = 1; i <= m; i++) G[i] = sub(mul(sub(S[m], S[m - i]), i), sum), sum = add(sum, S[i]);
    for(int i = 1; i <= m; i++) F[i] = G[i];
  }
  for(int i = 1; i <= m; i++) Ans = add(Ans, F[i]);
  cout << Ans << '\n';
  return 0;
}
