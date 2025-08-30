#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, a[301][301], q, f[301][301]; 
signed main() {
    freopen("glyph.in", "r", stdin);
    freopen("glyph.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];
    for (int i = 1; i <= q; ++i) {
        memset(f, 0x3f, sizeof(f));
        int xk, yk, xl, yl;
        cin >> xk >> xl >> yk >> yl;
        f[xk][yk] = 0;
        for (int x = xk; x <= xl; ++x)
            for (int y = yk; y <= yl; ++y)
                f[x][y] = min(f[x][y], min(f[x][y - 1], f[x - 1][y])) + a[x][y];
        cout << f[xl][yl] << '\n';
    }
    return 0;
}