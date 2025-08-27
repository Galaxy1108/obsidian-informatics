#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
typedef long long ll;
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
ll times(ll x, ll y, ll z) {
	if (y == 0) return 0;
	ll tmp = times(x, y / 2, z);
	if (y % 2 == 0) return (tmp + tmp) % z;
	else return (tmp + tmp + x) % z;
}
int main() {
	freopen("never.in", "r", stdin);
	freopen("never.out", "w", stdout);
	int T; read(T);
	while (T--) {
		ll n, s, t, x, y;
		read(n), read(s), read(t), read(x), read(y);
		if (t > s && (t - s) / y >= n) printf("%lld\n", s + n * y);
		else if (t < s && (s - t) / x >= n) printf("%lld\n", s - n * x);
		else {
			ll z = x + y;
			ll d = ((s + times(y, n, z) - t) % z + z) % z;
			if (d >= y) d -= z;
			printf("%lld\n", t + d);
		}
	}
	return 0;
}
