#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 5005;
const int M = 1e9 + 9;

int n, m, q;
int a[N][N];

signed main() {
    freopen("newfile.in", "r", stdin);
    freopen("newfile.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> q;
    for(int i = 1; i <= m; ++i) {
        for(int j = 1; j <= n; ++j) a[i][j] = a[i - 1][j];
        int l, r, x; cin >> l >> r >> x;
        for(int j = l; j <= r; ++j) a[i][j] = (a[i][j] + x) % M;
    }
    for(int i = 1; i <= m; ++i) for(int j = 1; j <= n; ++j) a[i][j] = (M + (a[i][j] + a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1]) % M) % M;
    for(int i = 1; i <= q; ++i) {
        int u, d, l, r; cin >> u >> d >> l >> r;
        int Ansn = (M + a[d][r] - a[d][l - 1]) % M;
        if(u != 0) Ansn = (M + Ansn - ((M + a[u - 1][r] - a[u - 1][l - 1]) % M) % M) % M;
        cout << Ansn << '\n';
    }
    return 0;
}