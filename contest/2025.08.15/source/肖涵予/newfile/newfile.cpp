#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5005;
const ll mod = 1e9 + 9;
int n, m, q;
ll ar[N][N], br[N][N], x, ans;
int main(void) {
	freopen("newfile.in", "r", stdin);
	freopen("newfile.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 1, l, r; i <= m; ++i) {
		scanf("%d %d %lld", &l, &r, &x);
		for (int j = 1; j <= n; ++j) ar[i][j] = (ar[i-1][j] + ((j >= l && j <= r) ? x : 0)) % mod;
	}
	for (int i = 1; i <= m; ++i) for (int j = 1; j <= n; ++j) br[i][j] = (br[i-1][j] + br[i][j-1] - br[i-1][j-1] + ar[i][j] + mod + mod) % mod;
	for (int i = 1, u, d, l, r; i <= q; ++i) {
		scanf("%d %d %d %d", &u, &d, &l, &r);
		ans = (br[d][r] - (u ? br[u-1][r] : 0) - (l ? br[d][l-1] : 0) + ((u && l) ? br[u-1][l-1] : 0) + mod + mod + mod) % mod;
		printf("%lld\n", ans);
	}
	return 0;
}
