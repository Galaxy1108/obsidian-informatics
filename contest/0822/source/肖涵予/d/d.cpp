#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int T, n, x[N], q;
bool check(int l, int r, int a, int b, int c) {
	for (int i = l, k = 0; i <= r; ++i, ++k)
		if ((a * k + b) / c != x[i])
			return false;
	return true;
}
int main(void) {
	freopen("d.in", "r", stdin);
	freopen("d.out", "w", stdout);
	cin.tie(0) -> ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; ++i)
			cin >> x[i];
		cin >> q;
		for (int t = 1, l, r; t <= q; ++t) {
			cin >> l >> r;
			if (n <= 20 && q <= 20) { // 10% data
				bool flag = false;
				for (int c = 1; c <= 10; ++c) {
					for (int a = 0; a <= 10; ++a) {
						for (int b = 0; b <= 10; ++b)
							if (check(l, r, a, b, c)) {
								cout << a << ' ' << b << ' ' << c << '\n';
								flag = true;
								break;
							}
						if (flag) break;
					}
					if (flag) break;
				}
			}
			else { // c = 1 Sp 1
				int b = x[l], a = 0;
				if (r > l) a = x[r] - x[r-1];
				else a = 0;
				cout << a << ' ' << b << ' ' << 1 << '\n';
			}
		}
	}
	return 0;
}
