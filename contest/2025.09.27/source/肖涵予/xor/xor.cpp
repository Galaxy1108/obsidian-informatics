#include <bits/stdc++.h>
using namespace std;
const int N = 3e3;
int n, a[N], num[N][N], mx[N][N], ans;
int main(void) {
	freopen("xor.in", "r", stdin), freopen("xor.out", "w", stdout);
	cin.tie(0) -> ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i)
		for (int j = i; j <= n; ++j)
			num[i][j] = num[i][j - 1] ^ a[j], mx[i][j] = max(mx[i][j - 1], a[j]);
	for (int i = 1; i <= n; ++i)
		for (int j = i; j <= n; ++j)
			if (num[i][j] <= mx[i][j])
				++ans;
	cout << ans;
	return 0;
}
