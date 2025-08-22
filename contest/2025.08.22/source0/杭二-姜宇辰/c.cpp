#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 5005;
int n, seed, Ans, A[MAXN][MAXN], B[MAXN][MAXN], Cur[MAXN], Id[MAXN];
void gen(){
  mt19937 rnd(seed);
  for(int i = 1; i <= n; i++) for(int j = 1; j <= n + 1; j++)
    if(seed) swap(A[i][j] = j, A[i][rnd() % j + 1]);
    else cin >> A[i][j];
  for(int i = 1; i <= n; i++) for(int j = 1; j <= n + 1; j++)
    B[i][A[i][j]] = j;
}
int sub(int x, int y){return (x -= y) <= 0? x + n: x;}
int main(){
  freopen("c.in", "r", stdin);
  freopen("c.out", "w", stdout);
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> seed, gen(), Ans = (n + 1) * (n + 2) / 2;
  for(int i = n; i; i--) for(int k = 1; k <= n + 1; k++)
    if(!Id[B[i][k]]){Id[B[i][Cur[i] = k]] = i, Ans -= B[i][k]; break;}
  cout << Ans;
  for(int i = 1; i < n; i++){
    Ans += B[i][Cur[i]], Id[B[i][Cur[i]]] = 0, Cur[i] = 0;
    for(int id = i, nxt; id; id = nxt){
      Ans += B[id][Cur[id]];
      do Cur[id]++; while(Id[B[id][Cur[id]]] && sub(Id[B[id][Cur[id]]], i) > sub(id, i));
      nxt = Id[B[id][Cur[id]]], Id[B[id][Cur[id]]] = id, Ans -= B[id][Cur[id]];
    } cout << ' ' << Ans;
  }
  cout << '\n';
  cerr << (double)clock() / CLOCKS_PER_SEC << endl;
  return 0;
}
