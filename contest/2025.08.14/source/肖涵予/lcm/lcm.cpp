#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 Int;
const int N = 21;
const int f[N] = {0, 1, 2, 5, 12, 29, 70, 169, 408, 985, 2378, 5741, 13860, 33461, 80782, 195025, 470832, 1136689, 2744210, 6625109, 15994428};
int T, n, p;
ll pow2[N];
Int C[N][N], g[N];
Int gcd(Int a, Int b) {
	return (a % b) ? gcd(b, a % b) : b;
}
Int lcm(Int a, Int b) {
	return a / gcd(a, b) * b;
}
void write(Int x) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	if (x > 9) write(x / 10);
	putchar(x % 10 + 48);
	return ;
}
int main(void) {
	freopen("lcm.in", "r", stdin);
	freopen("lcm.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &p);
		pow2[0] = 1;
		for (int i = 1; i <= n; ++i) pow2[i] = pow2[i-1] << 1;
		C[0][0] = C[1][0] = C[1][1] = 1;
		for (int i = 2; i <= n; ++i) {
			C[i][0] = C[i][i] = 1;
			for (int j = 1; j < i; ++j) C[i][j] = C[i-1][j] + C[i-1][j-1];
		}
		g[1] = f[1];
		for (int i = 2; i <= n; ++i) g[i] = lcm(g[i-1], f[i]);
		Int ans = 0;
		for (int i = 1; i <= n; ++i) ans = (ans + g[i] % p * i) % p;
		write(ans), putchar('\n');
	}
	return 0;
}
