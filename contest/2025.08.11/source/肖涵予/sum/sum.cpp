#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
ll S, k; 
int main(void) {
	freopen("sum.in", "r", stdin);
	freopen("sum.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> S >> k;
		ll num = (S - 1) / 2;
		if (k > num) cout << -1 << '\n';
		else cout << k * 2 << '\n';
	}
	return 0;
}
