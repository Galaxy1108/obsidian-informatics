#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 15;
int n, p;
ll C[N][N], F[N], G[N];
ll ans;
void upd(ll& x, ll y) {
	x = (x + y) % p;
	return ;
}
int main(void) {
	freopen("gonna.in", "r", stdin);
	freopen("gonna.out", "w", stdout);
	scanf("%d %d", &n, &p);
	C[0][0] = C[1][0] = C[1][1] = 1;
	for (int i = 2; i <= n; ++i) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; ++j)
			C[i][j] = C[i-1][j-1] + C[i-1][j];
	}
	for (int x = 1; x <= n; ++x) {
		F[x] = 1;
		for (int y = 0; y <= x; ++y)
			F[x] *= C[x][y];
	}
	for (int x = 1; x <= n; ++x) for (int y = 1; y <= (int)sqrt(F[x]); ++y) if (!(F[x] % y)) {
		upd(G[x], y);
		if (y * y < F[x]) upd(G[x], F[x] / y);	
	}
	for (int x = 1; x <= n; ++x)
		upd(ans, G[x]);
	printf("%d", ans);
	return 0;
}
