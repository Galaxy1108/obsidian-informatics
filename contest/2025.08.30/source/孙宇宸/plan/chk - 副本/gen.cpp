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

	uniform_int_distribution<int> a(2, 30);
	int n = a(rnd);
	uniform_int_distribution<int> b(1, n - 1);
	cout << n << ' ' << b(rnd) << '\n';
	for (int i = 2; i <= n; ++i) {
		uniform_int_distribution<int> uid(1, i - 1);
		cout << uid(rnd) << ' ' << i << '\n';
	}
	uniform_int_distribution<int> uid(1, 1000000);
	for (int i = 1; i <= n; ++i) {
		cout << uid(rnd) << ' ';
	}
	return 0;
}
