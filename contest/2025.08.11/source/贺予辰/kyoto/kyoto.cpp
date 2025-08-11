#include<bits/stdc++.h>
#define int long long
using namespace std;
int h, w, hh[1003], ww[1003], f[1003][1003];
signed main() {
    freopen("kyoto.in", "r", stdin);
    freopen("kyoto.out", "w", stdout);
    memset(f, 0, sizeof(f));
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> h >> w;
    if (h > 1e3 || w > 1e3) {
        cout << '\n';
        return 0;
    }
    for (int i = 1; i <= h; ++i) cin >> hh[i];
    for (int i = 1; i <= w; ++i) cin >> ww[i];
    for (int i = 1; i <= h; ++i)
        f[i][1] = ww[1] * (i - 1);
    for (int i = 1; i <= w; ++i)
        f[1][i] = hh[1] * (i - 1);
    for (int h0 = 2; h0 <= h; ++h0)
        for (int w0 = 2; w0 <= w; ++w0)
            f[h0][w0] =
            min(f[h0 - 1][w0] + ww[w0],
                f[h0][w0 - 1] + hh[h0]);
    cout << f[h][w] << '\n';
    return 0;
}
