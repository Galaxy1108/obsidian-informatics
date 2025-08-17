#include <bits/stdc++.h>
#define MAXN 5010
using namespace std;

int n, m, q;
long long a[MAXN], s[MAXN][MAXN];
const long long mod = 1e9 + 9;

int main()
{
    freopen("newfile.in","r",stdin);
    freopen("newfile.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> q;
	for (int i = 1; i <= m; ++i) {
		int l, r;
		long long val;
		cin >> l >> r >> val;
		for (int j = l; j <= r; ++j) a[j] = (a[j] + val) % mod;
		for (int j = 1; j <= n; ++j) s[i][j] = a[j]; 
	}
	for (int i = 1; i <= m; ++i) for (int j = 1; j <= n; ++j) s[i][j] = ((s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + s[i][j]) % mod + mod) % mod;
	for (int i = 1; i <= q; ++i) {
		int u, d, l, r;
		cin >> u >> d >> l >> r;
		if (u) --u;
		--l;
		cout << ((s[d][r] + s[u][l] - s[d][l] - s[u][r]) % mod + mod) % mod << "\n";
	}
    return 0;
}