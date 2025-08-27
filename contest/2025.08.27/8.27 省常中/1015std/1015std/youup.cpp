#include<bits/stdc++.h>
using namespace std;
const int MAXN = 6e5 + 5;
const int P = 998244353;
typedef long long ll;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
bool vis[MAXN];
int n, m, v[MAXN], e[MAXN];
int root, weight[MAXN], size[MAXN];
vector <pair <int, int>> a[MAXN];
vector <int> pre[MAXN];
void getroot(int pos, int fa, int tot) {
	size[pos] = 1, weight[pos] = 0;
	for (auto x : a[pos])
		if (!vis[x.first] && x.first != fa) {
			getroot(x.first, pos, tot);
			size[pos] += size[x.first];
			chkmax(weight[pos], size[x.first]);
		}
	chkmax(weight[pos], tot - size[pos]);
	if (weight[pos] < weight[root]) root = pos;
}
void dfs(int pos, int from, int fa, int depth) {
	if (pre[from].size() == depth) pre[from].push_back(0);
	pre[from][depth] += pos <= n;
	for (auto x : a[pos])
		if (!vis[x.first] && x.first != fa) {
			dfs(x.first, from, pos, depth + 1);
		}
}
void dfs(int pos) {
	pre[pos].clear();
	dfs(pos, pos, 0, 0);
	for (unsigned i = 1; i < pre[pos].size(); i++)
		pre[pos][i] += pre[pos][i - 1];
}
int query(int pos, int x) {
	if (x >= 0) {
		if (x >= pre[pos].size()) return pre[pos].back();
		else return pre[pos][x];
	} else return 0;
}
void getans(int pos, int fa, int from, int grom, int dist) {
	int add = query(from, dist - 1) - query(grom, dist - 2);
	v[pos] += query(from, dist) - query(grom, dist - 1), size[pos] = 1;
	for (auto x : a[pos])
		if (!vis[x.first] && x.first != fa) {
			getans(x.first, pos, from, grom, dist - 1);
			size[pos] += size[x.first];
			e[x.second] += add;
		}
}
void work(int pos, int tot) {
	vis[pos] = true;
	dfs(pos), v[pos] += query(pos, m);
	for (auto x : a[pos])
		if (!vis[x.first]) {
			dfs(x.first);
			e[x.second] += query(pos, m - 1);
			e[x.second] += query(x.first, m - 1) - query(x.first, m - 2);
			getans(x.first, pos, pos, x.first, m - 1);
			root = 0, getroot(x.first, pos, size[x.first]);
			work(root, size[x.first]);
		}
}
int x[1 << 20], y[1 << 20], z[1 << 20];
int fac[MAXN], inv[MAXN];
int power(int x, int y) {
	if (y == 0) return 1;
	int tmp = power(x, y / 2);
	if (y % 2 == 0) return 1ll * tmp * tmp % P;
	else return 1ll * tmp * tmp % P * x % P;
}
void update(int &x, int y) {
	x += y;
	if (x >= P) x -= P;
}
namespace FFT {
	const int MAXN = 1 << 20;
	const int G = 3;
	int N, Log, home[MAXN];
	void FFTinit(int n) {
		N = 1, Log = 0;
		while (N <= 2 * n) {
			N <<= 1;
			Log++;
		}
		for (int i = 0; i < N; i++) {
			int tmp = i, res = 0;
			for (int j = 1; j <= Log; j++) {
				res <<= 1;
				res |= tmp & 1;
				tmp >>= 1;
			}
			home[i] = res;
		}
	}
	void FFT(int *a, int mode) {
		for (int i = 0; i < N; i++)
			if (home[i] > i) swap(a[i], a[home[i]]);
		for (int len = 2; len <= N; len <<= 1) {
			int delta = power(G, (P - 1) / len);
			if (mode == -1) delta = power(delta, P - 2);
			for (int i = 0; i < N; i += len) {
				int now = 1;
				for (int j = i, k = i + len / 2; k < i + len; j++, k++) {
					int tmp = a[j], tnp = 1ll * a[k] * now % P;
					a[j] = (tmp + tnp >= P) ? (tmp + tnp - P) : (tmp + tnp);
					a[k] = (tmp - tnp < 0) ? (tmp - tnp + P) : (tmp - tnp);
					now = 1ll * now * delta % P;
				}
			}
		}
		if (mode == -1) {
			int inv = power(N, P - 2);
			for (int i = 0; i < N; i++)
				a[i] = 1ll * a[i] * inv % P;
		}
	}
	void times(int n, int *a, int *b, int *c) {
		FFTinit(n);
		FFT(a, 1), FFT(b, 1);
		for (int i = 0; i < N; i++)
			c[i] = 1ll * a[i] * b[i] % P;
		FFT(c, -1);
	}
}
int main() {
	freopen("youup.in", "r", stdin);
	freopen("youup.out", "w", stdout);
	int num; read(num);
	read(n), read(m);
	for (int i = 1; i <= n - 1; i++) {
		int x, y; read(x), read(y);
		a[x].emplace_back(i + n, i);
		a[i + n].emplace_back(x, i);
		a[y].emplace_back(i + n, i + n - 1);
		a[i + n].emplace_back(y, i + n - 1);
	}
	weight[root = 0] = n * 2 + 1;
	getroot(1, 0, n * 2);
	work(root, n * 2);
	fac[0] = inv[0] = 1;
	for (int i = 1; i <= n; i++) {
		fac[i] = 1ll * fac[i - 1] * i % P;
		inv[i] = power(fac[i], P - 2);
	}
	for (int i = 1; i <= n * 2; i++)
		x[n - v[i]]++, x[n - e[i]]--;
	for (int i = 0; i <= n; i++) {
		x[i] = 1ll * (x[i] + P) * fac[n - i] % P;
		y[i] = inv[i];
	}
	FFT :: times(n, x, y, z);
	for (int i = 1; i <= n; i++)
		printf("%lld ", 1ll * z[n - i] * inv[i] % P);
	printf("\n");
	return 0;
}