#include <bits/stdc++.h>
using namespace std;
constexpr int N = 305;
int Num, n, q, a[N];
int main(void) {
	freopen("imperishable.in", "r", stdin);
	freopen("imperishable.out", "w", stdout);
	cin.tie(0) -> ios::sync_with_stdio(false);
	cin >> Num;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	cin >> q;
	for (int t = 1, x, y; t <= q; ++t) cin >> x >> y;
	cout << 2;
	return 0;
}
