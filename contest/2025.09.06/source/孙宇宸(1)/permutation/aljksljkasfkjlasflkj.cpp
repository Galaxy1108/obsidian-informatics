#include <bits/stdc++.h>
using namespace std;

using ui = unsigned;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

#ifdef jiji
template <typename T, typename... Args>
void dbg(const T &first, Args... args) {
	cerr << first;
	if constexpr (sizeof...(args)) {
		cerr.put(' ');
		dbg(args...);
	} else {
		cerr << endl;
	}
}
#endif

constexpr int N = 100000 + 1, P = 998244353;

int p[N], q[N], r[N], h[N], que[N], fa[N], nh[N], r1[N], r2[N], pp[N];
vector<pii> adj[N];
vector<int> blk[N];
bitset<N> vis, nv;
int ff(int x) {
	return x == fa[x] ? x : fa[x] = ff(fa[x]);
}

mt19937 rnd{random_device{}()};
void solve() {
	int n = 5;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> q[i];
	}
	iota(pp + 1, pp + n + 1, 1);
	do {
		for (int i = 1; i <= n; ++i) {
			r1[i] = p[pp[i]];
			r2[i] = pp[q[i]];
		}
		bool flag = true;
		for (int i = 1; i <= n; ++i) {
			flag &= r1[i] == r2[i];
		}
		if (flag) {
			for (int i = 1; i <= n; ++i) {
				cout << pp[i] << ' ';
			}
			cout << '\n' << flush;
			return ;
		}
	} while (next_permutation(pp + 1, pp + n + 1));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
//	freopen("permutation.in", "r", stdin);
//	freopen("permutation.out", "w", stdout);
	
		solve();
	return 0;
}
