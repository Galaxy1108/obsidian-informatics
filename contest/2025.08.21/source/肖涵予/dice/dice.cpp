#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll Mod = 1e9 + 7;
const int N = 5005;
int n;
ll a[N];
bool check_equal(void) {
	for (int i = 1, j = 2; i < n; ++i, ++j)
		if (a[i] != a[j]) return false;
	return true;
}
ll qpow(ll base, int power) {
	ll res = 1;
	while (power) {
		if (power & 1) res = res * base % Mod;
		base = base * base % Mod;
		power >>= 1;
	}
	return res;
}
int main(void) {
	freopen("dice.in", "r", stdin);
	freopen("dice.out", "w", stdout);
	cin.tie(0) -> ios::sync_with_stdio(false);
	cin >> n;
	ll tot = 1, ans = 0, V = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		V = max(V, a[i]);
		tot = tot * a[i] % Mod;
	}
	for (ll x = 1; x <= V; ++x) {
		int num = 0;
		ll mul = 1;
		for (int i = 1; i <= n; ++i) {
			if (a[i] >= x) ++num;
			else mul = mul * a[i] % Mod;
		}
		ll res = ((qpow(x, num) + Mod - qpow(x - 1, num)) % Mod) * mul % Mod;
		ans = (ans + res * x % Mod) % Mod;
	}
	ans = ans * qpow(tot, Mod - 2) % Mod;
	cout << ans;
	return 0;
}
