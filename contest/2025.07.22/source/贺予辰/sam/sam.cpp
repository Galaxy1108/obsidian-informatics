#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int lzj = 1e9 + 7;
int k;
struct Mtrx {
	int val[10][10];
	int * operator [] (int pos) {
		return val[pos];
	}
	void init() {
		memset(val, 0, sizeof(val));
	}
	void init_e() {
		memset(val, 0, sizeof(val));
		for (int i = 0; i < 10; ++i)
			val[i][i] = 1;
	}
} trns;
struct Drct {
	int val[10];
	void init() {
		memset(val, 0, sizeof(val));
	}
	int operator [] (int pos) {
		return val[pos];
	}
} g2;
Mtrx operator * (Mtrx a, Mtrx b) {
	Mtrx ans;
	ans.init();
	for (int i = 0; i < 10; ++i)
		for (int j = 0; j < 10; ++j)
			for (int k = 0; k < 10; ++k)
				ans[i][j] =
				(a[i][k] * b[k][j] % lzj + ans[i][j]) % lzj;
	return ans;
}
Drct operator * (Mtrx a, Drct b) {
	Drct ans;
	ans.init();
	for (int i = 0; i < 10; ++i)
		for (int k = 0; k < 10; ++k)
			ans.val[i] =
			(a[i][k] * b.val[k] % lzj + ans.val[i]) % lzj;
	return ans;
}
Mtrx qpow(Mtrx a, int b) {
	Mtrx ans;
	for (ans.init_e(); b; b >>= 1, a = a * a)
		if (b & 1) ans = ans * a;
	return ans;
}
signed main() {
	freopen("sam.in", "r", stdin);
	freopen("sam.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> k;
	if (k == 1) {
		cout << 10 << endl;
		return 0;
	}
	g2.val[0] = 2, g2.val[1] = 3, g2.val[2] = 4, g2.val[3] = 5,
	g2.val[4] = 5, g2.val[5] = 5, g2.val[6] = 5, g2.val[7] = 5,
	g2.val[8] = 4, g2.val[9] = 3, trns.init();
	for (int i = 0; i < 10; ++i)
		for (int j = 0; j < 10; ++j)
			if (abs(i - j) <= 2) trns[i][j] = 1;
	trns = qpow(trns, k - 2ll);
	g2 = trns * g2;
	int ans = 0;
	for (int i = 0; i < 10; ++i)
		ans = (ans + g2[i]) % lzj;
	cout << ans << endl;
	return 0;
}
//9:10 T1 AC 100 + 0 + 0 + 0 = 100pts
