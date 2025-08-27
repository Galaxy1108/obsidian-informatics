#include <bits/stdc++.h>
using namespace std;

using ui = unsigned;
using ll = long long;
using lll = __int128_t;

constexpr int N = 20000 + 10;

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

vector<int> vec[N], prm, g[2300];
bitset<N> vis;
int cnt[N], now[N];
vector<pair<int, int>> v[N];

void solve() {
	int n, p;
	cin >> n >> p;
	for (int i = 2; i <= n; ++i) {
		if (!vis[i]) {
			prm.push_back(i);
		}
		for (int j : prm) {
			int nj = i * j;
			if (nj > n) {
				break;
			}
			vis[nj] = true;
			if (!(i % j)) {
				break;
			}
		}
	}
	map<int, int> mp;
	auto bd = [&](int x) {
		mp.clear();
		for (int i = 2; i * i <= x; ++i) {
			if (!(x % i)) {
				int &y = ++mp[i];
				x /= i;
				while (!(x % i)) {
					++y;
					x /= i;
				}
			}
		}
		if (x > 1) {
			++mp[x];
		}
	};
	for (int i = 2; i <= n; ++i) {
		bd(i);
		v[i].reserve(mp.size());
		for (auto [key, val] : mp) {
//			dbg(i, key, val);
			v[i].emplace_back(key, val);
		}
	}
	
	int pcnt = (int)prm.size();
	for (int i = 0; i < pcnt; ++i) {
		g[i] = {1};
	}
	auto calc = [&](int i, int j) {
		if ((int)g[i].size() >= j + 1) {
			return g[i][j];
		}
		int pre = (int)g[i].size();
		g[i].resize(j + 1);
		for (int k = pre; k <= j; ++k) {
			g[i][k] = ((ll)g[i][k - 1] * prm[i] + 1) % p;
		}
		return g[i][j];
	};
	
	ll sum = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j : prm) {
			if (j > i) {
				break;
			}
			cnt[j] -= now[j];
		}
		for (auto [key, val] : v[i]) {
			now[key] += val;
			cnt[key] += val * (i - 1);
		}
		
		int mul = 1;
		for (int j = 0; j < pcnt; ++j) {
			if (prm[j] > i) {
				break;
			}
//			dbg("???", i, prm[j], cnt[prm[j]]);
			mul = (ll)mul * calc(j, cnt[prm[j]]) % p;
		}
//		dbg("!!!", i, mul);
		sum += mul;
	}
	cout << sum % p << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("gonna.in", "r", stdin);
	freopen("gonna.out", "w", stdout);
	
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}		
	return 0;
}
