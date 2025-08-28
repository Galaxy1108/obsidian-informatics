#include <bits/stdc++.h>
#define ls(p) (p << 1)
#define rs(p) (p << 1 | 1)
using namespace std;
typedef long long ll;
constexpr int N = 200005;
int n, q;
ll a[N];
void Solve_Sub1(void) {
	for (int t = 1, op, l, r; t <= q; ++t) {
		static ll v;
		cin >> op;
		if (op == 1) {
			cin >> v;
			for (int i = 1; i <= n; ++i)
				a[i] = min(a[i], v);
		}
		else if (op == 2)
			for (int i = 1; i <= n; ++i)
				a[i] += i;
		else {
			cin >> l >> r;
			ll res = 0;
			for (int i = l; i <= r; ++i)
				res += a[i];
			cout << res << '\n';
		}
	}
	return ;
}
int main(void) {
	freopen("easy.in", "r", stdin);
	freopen("easy.out", "w", stdout);
	cin.tie(0) -> ios::sync_with_stdio(false);
	cin >> n >> q;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	if (n <= 8000 && q <= 8000) { // Sub1
		Solve_Sub1();
		return 0;
	}
	return 0;
}
