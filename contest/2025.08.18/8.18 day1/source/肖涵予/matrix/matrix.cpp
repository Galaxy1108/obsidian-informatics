#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, m, k, a[N][2], ans;
int main(void) {
	freopen("matrix.in", "r", stdin);
	freopen("matrix.out", "w", stdout);
	cin.tie(0) -> ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i][0] >> a[i][1];
		if (a[i][0] > 0) ans += a[i][0];
		if (a[i][1] > 0) ans += a[i][1];
	}
	cout << ans;
	return 0;
}
