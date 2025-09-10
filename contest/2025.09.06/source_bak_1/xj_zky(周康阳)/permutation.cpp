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
int n, m, p[N], q[N], h[N], ih[N];
vector < vi > A[N];
vector < vi > B[N];
bool vis[N];
int main() { 
//	return system("fc graph.out graph5.out"), 0;
	freopen("permutation.in", "r", stdin);
	freopen("permutation.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin >> n;
	L(i, 1, n) cin >> p[i];
	L(i, 1, n) cin >> q[i];
	me(vis, 0);
	L(i, 1, n) if(!vis[i]) {
		vi vt;
		int x = i;
		while(!vis[x]) vis[x] = true, vt.emplace_back(x), x = p[x];
		A[sz(vt)].emplace_back(vt);
	}
	
	me(vis, 0);
	L(i, 1, n) if(!vis[i]) {
		vi vt;
		int x = i;
		while(!vis[x]) vis[x] = true, vt.emplace_back(x), x = q[x];
		B[sz(vt)].emplace_back(vt);
	}
	
	L(i, 1, n) 
		if(sz(A[i]) != sz(B[i])) {
			cout << "NO\n";
			return 0;
		}
	
	L(i, 1, n) {
		L(t, 0, sz(A[i]) - 1) {
			L(j, 0, i - 1) {
				h[B[i][t][j]] = A[i][t][j];
			}
		}
	}
	
	cout << "YES\n";
	L(i, 1, n) 
		cout << h[i] << ' ';
	cout << '\n';
	
	L(i, 1, n) ih[h[i]] = i;
	L(i, 1, n) {
		if(ih[p[h[i]]] != q[i]) {
			cout << "QAQ\n";
		}
	}
	return 0;
} 