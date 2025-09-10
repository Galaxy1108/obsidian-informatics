#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int > 
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long
#define ld __float128
using namespace std;
const int N = 1e6 + 7, T = 1e6, mod = 998244353;
int n, m;
int u[N], v[N];
int siz[N], f[N];
inline int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
} 
int ns;
int main() { 
//	return system("fc graph.out graph5.out"), 0;
	freopen("graph.in", "r", stdin);
	freopen("graph.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin >> n >> m;
	L(i, 1, n) {
		f[i] = i;
	}
	L(i, 1, m) {
		cin >> u[i] >> v[i];
		f[find(u[i])] = find(v[i]);
	}
	L(i, 1, m) {
		siz[find(u[i])] += 1;
	}
	L(i, 1, n) 
		ns += siz[i] / 2;
	cout << ns << '\n';
	return 0;
} 