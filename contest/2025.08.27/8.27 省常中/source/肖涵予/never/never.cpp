#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int Q;
ll N, S, T, X, Y;
int main(void) {
	freopen("never.in", "r", stdin);
	freopen("never.out", "w", stdout); 
	cin.tie(nullptr) -> ios::sync_with_stdio(false);
	cin >> Q;
	while (Q--) {
		cin >> N >> S >> T >> X >> Y;
		if (N <= 1000000ll) { // 20% of data
			while (N--) {
				if (S >= T) S -= X;
				else S += Y;
			}
			cout << S << '\n';
			continue;
		}
		// Sp : X = Y 
		if (S < T) {
			ll num = (T - S - 1) / Y;
			if (N < num) {
				cout << (S + N * Y) << '\n';
				continue;
			}
			ll now = S + num * Y;
			N -= num;
			if (N % 2) cout << (now + Y) << '\n';
			else cout << now << '\n';
		}
		else {
			ll num = (S - T) / X;
			if (N < num) {
				cout << (S - N * X) << '\n';
				continue;
			}
			ll now = S - num * X;
			N -= num;
			if (N % 2) cout << (now - X) << '\n';
			else cout << now << '\n';
		}
	}
	return 0;
}
