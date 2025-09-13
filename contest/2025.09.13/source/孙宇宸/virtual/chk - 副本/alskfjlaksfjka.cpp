#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int N = 200000 + 1, P = 998244353;

int a[N];
bitset<N> vis;

void solve() {
	int n;
	cin >> n;
	auto to = [](int u) {
		return u + a[u];
	};
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	
	int ans = 0;
	for (int x = 1; x <= n; ++x) {
		for (int y = -n; y <= n; ++y) {
			int h = a[x];
			a[x] = y;
			
			int u = 1;
			for (int i = 1; i <= n; ++i) {
				vis[i] = false;
			}
			vis[u] = true;
			bool flag = true;
			while (u <= n) {
				if (to(u) <= 0 || to(u) > n) {
					break;
				}
				if (vis[to(u)]) {
					flag = false;
					break;
				}
				u = to(u);
				vis[u] = true;
			}
			
			if (!flag) {
				cout << x << ' ' << y << '\n';
			}
			
			ans += flag;
			
			a[x] = h;
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	#ifdef jiji
	freopen("input.txt", "r", stdin);
#endif
	
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
