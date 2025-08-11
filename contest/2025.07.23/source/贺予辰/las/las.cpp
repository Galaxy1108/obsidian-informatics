#include<bits/stdc++.h>
using namespace std;
int c[1000006][2], ans[1000006][2], n, k[1000006][2];
bool fl[2] = {0, 0};
bool chk(bool l) {
	for (int i = 0; i < n; ++i) {
		if (k[ans[i][l]][l] < c[(ans[i][l] - i) ^ 1 + i][l])
			return false;
	}
	return true;
}
int main() {
	freopen("las.in", "r", stdin);
	freopen("las.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	ans[0][0] = 0, ans[0][1] = 1;
	for (int i = 0; i < n; ++i)
		cin >> c[i][0], c[i][1] = c[i][0] *= 2;
	c[0][0] /= 2, c[1][1] /= 2,
	k[0][0] = c[0][0] * 2, k[0][1] = c[1][1] * 2;
	for (int i = 1; i < n; ++i) {
		if (c[i][0] > c[(i + 1) % n][0])
			ans[i][0] = i, k[i][0] = c[i][0];
		else ans[i][0] = (i + 1) % n,
			k[i][0] = c[(i + 1) % n][0], c[(i + 1) % n][0] /= 2;
	}
	if (ans[n - 1] == 0) c[0][0] *= 2;
	if (chk(0)) {
		for (int i = 0; i < n; ++i)
			cout << ans[i][0] + 1 << ' ';
		return 0;
	}
	for (int i = 1; i < n; ++i) {
		if (c[i][1] > c[(i + 1) % n][1])
			ans[i][1] = i, k[i][1] = c[i][1];
		else ans[i][1] = (i + 1) % n,
			k[i][1] = c[(i + 1) % n][1], c[(i + 1) % n][1] /= 2;
	}
	if (chk(1)) {
		for (int i = 0; i < n; ++i)
			cout << ans[i][0] + 1 << ' ';
		return 0;
	}
	cout << "NIE" << endl;
	return 0;
}
