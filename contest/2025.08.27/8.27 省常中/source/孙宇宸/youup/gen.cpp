#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int N = 200000 + 1, P = 998244353;

void solve() {
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t = 1;
	cout << t << '\n';
	mt19937_64 rnd{random_device{}()};
	uniform_int_distribution<int> a(1, 1000000000);
	uniform_int_distribution<ll> b(1ll, (ll)1e18);
	uniform_int_distribution<ll> c((ll)-1e18, (ll)1e18);
//	uniform_int_distribution<int> a(1, 3);
//	uniform_int_distribution<ll> b(1ll, 10ll);
//	uniform_int_distribution<ll> c(-10ll, 10ll);
	while (t--) {
		cout << a(rnd) << ' ' << c(rnd) << ' ' << c(rnd) << ' ' << b(rnd) << ' ' << b(rnd) << '\n';
	}
	return 0;
}
