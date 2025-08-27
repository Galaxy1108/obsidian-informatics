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
const int N = 2e5 + 7;

ll m, s, n;
bitset < N > f, g;
int a[N], mx;
// Prod_{i \in S} (sum_{j} x^{a_j * 2^i}) 
void Main() {
	cin >> m >> s >> n, mx = 0;
	L(i, 1, n) cin >> a[i], mx = max(mx, a[i]);
	++mx; 
	f.reset(), f.set(0);
	R(o, 60, 0) {
		g.reset();
		L(i, 0, mx) if(f[i]) g.set(i * 2);
		if(s >> o & 1) 
			g <<= 1;
		if(m >> o & 1) {
			f.reset();
			L(i, 1, n) f ^= g >> a[i];
		} else {
			f = g;
		}
	}
	if(f[0]) {
		cout << 1 << '\n';
	} else {
		cout << 0 << '\n';
	}
}

int main() {
//	return system("fc ex_give3.out give.out"), 0;
	freopen("give.in", "r", stdin);
	freopen("give.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}