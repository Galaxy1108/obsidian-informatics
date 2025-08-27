#include <bits/stdc++.h>
using namespace std;

using ui = unsigned;
using ull = unsigned long long;
using ll = long long;
using lll = __int128_t;

constexpr ui N = 20000 + 10;

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

vector<ui> vec[N], prm, g[2300];
bitset<N> vis;
ui cnt[N], now[N];
vector<pair<ui, ui>> v[N];

ui rd() {	
	ui x;
	cin >> x;
	return x;
}

void solve() {
	const ui n = rd(), p = rd();
	for (ui i = 2; i <= n; ++i) {
		if (!vis[i]) {
			prm.push_back(i);
		}
		for (ui j : prm) {
			ui nj = i * j;
			if (nj > n) {
				break;
			}
			vis[nj] = true;
			if (!(i % j)) {
				break;
			}
		}
	}
	map<ui, ui> mp;
	auto bd = [&](ui x) {
		mp.clear();
		for (ui i = 2; i * i <= x; ++i) {
			if (!(x % i)) {
				ui &y = ++mp[i];
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
	for (ui i = 2; i <= n; ++i) {
		bd(i);
		v[i].reserve(mp.size());
		for (auto [key, val] : mp) {
//			dbg(i, key, val);
			v[i].emplace_back(key, val);
		}
	}
	
	ui pcnt = (ui)prm.size();
	for (ui i = 0; i < pcnt; ++i) {
		g[i] = {1};
	}
	auto calc = [&](ui i, ui j) {
		if ((ui)g[i].size() >= j + 1) {
			return g[i][j];
		}
		ui pre = (ui)g[i].size();
		g[i].resize(j + 1);
		for (ui k = pre; k <= j; ++k) {
			g[i][k] = ((ull)g[i][k - 1] * prm[i] + 1) % p;
		}
		return g[i][j];
	};
	
	ull sum = 0;
	for (ui i = 1; i <= n; ++i) {
		for (ui j : prm) {
			if (j > i) {
				break;
			}
			cnt[j] -= now[j];
		}
		for (auto [key, val] : v[i]) {
			now[key] += val;
			cnt[key] += val * (i - 1);
		}
		
		ui mul = 1;
		for (ui j = 0; j < pcnt; ++j) {
			if (prm[j] > i) {
				break;
			}
//			dbg("???", i, prm[j], cnt[prm[j]]);
			mul = (ull)mul * calc(j, cnt[prm[j]]) % p;
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
	
	ui t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}		
	return 0;
}
