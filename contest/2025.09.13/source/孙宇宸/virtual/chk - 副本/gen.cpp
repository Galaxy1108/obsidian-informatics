#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int N = 200000 + 1, P = 998244353;

void solve() {
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	mt19937 rnd{random_device{}()};
	
	int n = rnd() % 100000 + 1, l = rnd() % n + 1, r = rnd() % n + 1;
	if (l > r) {
		swap(l, r);
	}
	cout << n << ' ' << l << ' ' << r << '\n';
	for (int i = 1; i <= n; ++i) {
		cout.put((rnd() & 1) + 'a');
	}
	cout << '\n';
	int q = 100000;
	cout << q << '\n';
	while (q--) {
		int u = rnd() % n + 1, v = rnd() % n + 1;
		cout << u << ' ' << v << '\n';
	}
	return 0;
}
