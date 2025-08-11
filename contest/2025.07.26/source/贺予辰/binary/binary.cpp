#include<bits/stdc++.h>
using namespace std;
const char blk = 32;
int n, m, x, y, l[15], h[15];
char ans[805][4000];
bool fl[15][4000];
void del(int x, int y) {
    if (y > m) return;
    fl[y][x] = 1;
    del((x << 1) - 1, y + 1), del(x << 1, y + 1);
}
int main() {
    freopen("binary.in", "r", stdin);
    freopen("binary.out", "w", stdout);
    memset(ans, 0, sizeof(ans));
    memset(fl, 0, sizeof(fl));
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> m >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> y >> x;
        del(x, y);
    }
    l[m] = 0, l[m - 1] = 3;
    for (int i = m - 2; i >= 1; --i)
        l[i] = l[i + 1] << 1;
    h[1] = 1;
    for (int i = 2; i < m; ++i)
        h[i] = h[i - 1] + l[i];
    h[m] = h[m - 1] + 2;
    for (int i = 0; i <= l[1]; ++i) ans[1][i] = blk;
    ans[1][l[1]] = 'o';
    for (int i = 2, cnt = 2; i <= h[m]; ++i) 
        if (i == h[cnt]) {
            ++cnt;
            for (int j = 1; j <= l[1] << 1 + 1; ++j)
                if (ans[i - 1][j + 1] == '/' || ans[i - 1][j - 1] == '\\')
                    ans[i][j] = 'o';
                else ans[i][j] = blk;
        } else if (i - 1 == h[cnt - 1]) {
            for (int j = 1; j <= l[1] << 1 + 1; ++j)
                if (ans[i - 1][j + 1] == 'o')
                    ans[i][j] = '/';
                else if (ans[i - 1][j - 1] == 'o')
                    ans[i][j] = '\\';
                else ans[i][j] = blk;
        } else {
            for (int j = 1; j <= l[1] << 1 + 1; ++j)
                if (ans[i - 1][j + 1] == '/') ans[i][j] = '/';
                else if (ans[i - 1][j - 1] == '\\') ans[i][j] = '\\';
                else ans[i][j] = blk;
        }
    for (int i = 1, cnt = 1; i <= h[m]; ++i) {
        for (int j = 1, now = 1; j <= l[1] << 1 + 1; ++j) {
            if (fl[cnt][now]) cout << blk;
            else cout << ans[i][j];
            if (ans[i][j] != blk) ++now;
        }
        if (i == h[cnt]) ++cnt;
        cout << '\n';
    }
}
// 9:45 T1 AC 100 + 0 + 0 + 0 = 100pts