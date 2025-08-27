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
const int N = 1e6 + 7;
int n, mod;
int ns[N], c[N], pre[N];
bool Prime[N];
int qpow(int x, int y) {
	int ret = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) ret = (ll) ret * x % mod;
	return ret;
}
struct node { // * v + t.
	int v, t;
	inline node (int V = 0, int T = 0) {
		v = V, t = T;
	}
};
inline node operator * (node a, node b) {
	return node((ll) a.v * b.v % mod, ((ll) a.t * b.v + b.t) % mod);
}
node f[N], g[N];

int main() {
//	return system("fc ex_gonna3.out gonna.out"), 0;
	freopen("gonna.in", "r", stdin);
	freopen("gonna.out", "w", stdout); 
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> mod;
	L(i, 2, n) Prime[i] = 1;
	L(i, 2, n) if(Prime[i]) for(int j = i * 2; j <= n; j += i) Prime[j] = false;
	L(i, 1, n) ns[i] = 1;
	L(p, 2, n) if(Prime[p]) {
		L(i, 0, n) {
			c[i] = 0;
			int cur = i / p;
			while(cur) c[i] += cur, cur /= p;
		}
		L(i, 1, n) pre[i] = pre[i - 1] + c[i];
		int qwq = c[n] * (n + 1), S = sqrt(qwq) + 1;
		node cur = node(p, 1);
		f[0] = g[0] = node(1, 0);
		L(i, 1, S) f[i] = f[i - 1] * cur; 
		L(i, 1, S) g[i] = g[i - 1] * f[S];
		L(i, 1, n) {
			int r = c[i] * (i + 1) - pre[i] * 2;
			node cur = f[r % S] * g[r / S];
			ns[i] = (ll) ns[i] * (cur.v + cur.t) % mod;
		}
	}
	int ret = 0;
	L(i, 1, n) (ret += ns[i]) %= mod;
	cout << ret << '\n';
	return 0;
}