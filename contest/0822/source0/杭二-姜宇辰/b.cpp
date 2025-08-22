#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 2005;
int n, mn = INT_MAX, A[MAXN][MAXN]; int64_t F[MAXN];
void Dij(){
  priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>, greater<pair<int64_t, int>>> Q;
  for(int i = 1; i <= n; i++) Q.emplace(F[i], i);
  while(!Q.empty()){
    auto [dis, id] = Q.top(); Q.pop(); if(dis != F[id]) continue;
    for(int nxt = 1; nxt <= n; nxt++) if(nxt != id && dis + A[id][nxt] < F[nxt])
      Q.emplace(F[nxt] = dis + A[id][nxt], nxt);
  }
}
int main(){
  freopen("b.in", "r", stdin);
  freopen("b.out", "w", stdout);
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  for(int i = 1; i <= n; i++) for(int j = i + 1; j <= n; j++)
    cin >> A[i][j], mn = min(mn, A[j][i] = A[i][j]);
  for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) if(i != j) A[i][j] -= mn;
  for(int i = 1; i <= n; i++){
    F[i] = INT64_MAX;
    for(int j = 1; j <= n; j++) if(i != j) F[i] = min<int64_t>(F[i], A[i][j] * 2);
  }
  Dij();
  for(int i = 1; i <= n; i++) cout << (int64_t)mn * (n - 1) + F[i] << '\n';
  return 0;
}
