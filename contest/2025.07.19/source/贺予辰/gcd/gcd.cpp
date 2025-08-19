#include<bits/stdc++.h>
#define int long long
using namespace std;
int a, b, c, d, k, T, mu[1000006], mus[1000006], prm[1000006],
cnt = 0;
bool inp[1000006];
void getmu(int n) {
	memset(inp, 0, sizeof(inp));
	mus[0] = 0, inp[1] = 1, mu[1] = 1;
	for (int i = 2; i <= n; ++i) {
		if (!inp[i]) mu[i] = -1, prm[cnt++] = i;
		for (int j = 0; j < cnt && i * prm[j] <= n; ++j) {
			inp[i * prm[j]] = 1;
			if (i % prm[j] == 0) {
				mu[i * prm[j]] = 0;
				break;
			}
			mu[i * prm[j]] = mu[i] * mu[prm[j]];
		}
	}
	for (int i = 1; i <= n; ++i) mus[i] = mus[i - 1] + mu[i];
}
int solve(int n, int m) {
	int ans = 0, tp = min(n, m);
	for (int l = 1, r; l <= tp; l = r + 1) {
		r = min(tp, min(n / (n / l), m / (m / l)));
		ans += (n / l) * (m / l) * (mus[r] - mus[l - 1]);
	}
	return ans;
}
signed main() {
	freopen("gcd.in", "r", stdin);
	freopen("gcd.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	getmu(1e6);
	cin >> T;
	while (T--) {
		cin >> a >> b >> c >> d >> k;
		a /= k, b /= k, c /= k, d /= k;
		int ans = solve(b, d) + solve(a - 1, c - 1) - solve(a - 1, d) - solve(b, c - 1);
		cout << ans << endl;
	}
	return 0;
}
