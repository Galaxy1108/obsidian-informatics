#include<bits/stdc++.h>
#define int long long
using namespace std;
const int lzj = 998244353;
int n, m, f[5003][5003], k, l = 0, s[5003], ans = 0;
signed main() {
	freopen("mex.in", "r", stdin);
	freopen("mex.out", "w", stdout);
    memset(f, 0, sizeof(f));
    memset(s, 0, sizeof(s));
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> s[i], l += s[i] ^ 1;
    f[0][0] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= min(m + 1, i); ++j)
            f[i][j] = s[i] ? f[i - 1][j - 1] :
            (f[i - 1][j] * j % lzj + 
            f[i - 1][j - 1] *
            (m - j + 1) % lzj) % lzj;
    for (int i = 1; i <= min(m + 1, n); ++i)
		ans = (ans + f[n][i]) % lzj;
    cout << ans << '\n';
    return 0;
}
// 9:45 T1 AC 100 + 0 + 0 + 0 = 100pts
