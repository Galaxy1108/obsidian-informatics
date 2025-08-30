#include<bits/stdc++.h>
using namespace std;
vector<int> a[3628805];
int n, cnt = 0, nw;
bool fl = 1;
bool pd(int c, int n) {
    for (int i = 0; i < c; ++i) {
        int fl = 0;
        for (int j = 0; j < n; ++j)
            if (abs(a[i][j] - a[c][j]) > 1)
                fl = 1;
        if (!fl) return 0;
    }
    return 1;
}
signed main() {
    freopen("constr.in", "r", stdin);
    freopen("constr.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
	const int st = clock();
    cin >> n;
    for (int i = 1; i <= n; ++i)
        a[cnt].push_back(i);
    nw = clock();
    while (nw - st <= 910) {
        for (int i = 0; i < n; ++i)
            a[cnt + 1].push_back(a[cnt][i]);
        fl = 0, ++cnt;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                swap(a[cnt][i], a[cnt][j]);
                fl |= pd(cnt, n);
                if (fl) break;
                swap(a[cnt][i], a[cnt][j]);
            }
            if (fl) break;
        }
        nw = clock();
    }
    cout << cnt << '\n';
     for (int i = 0; i < cnt; ++i) {
         for (int j = 0; j < n; ++j)
             cout << a[i][j] << ' ';
         cout << '\n';
     }
    return 0;
}
