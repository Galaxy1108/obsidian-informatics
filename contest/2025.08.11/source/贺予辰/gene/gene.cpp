#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int n, a[1000006], cl[1000006], cr[1000006], l, r;
int al, ar, fl = 0, fr = 0;
int main() {
    freopen("gene.in", "r", stdin);
    freopen("gene.out", "w", stdout);
    memset(cl, 0, sizeof(cl));
    memset(cr, 0, sizeof(cr));
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> l >> r;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= r; ++i) ++cl[a[i]];
    for (int i = l; i <= n; ++i) ++cr[a[i]];
    for (al = l - 1; al >= 1; --al)
        if (cl[a[al]] == 1) break;
    for (ar = r + 1; ar <= n; ++ar)
        if (cr[a[ar]] == 1) break;
    if (al < 1 || ar > n) {
        cout << -1 << endl;
        return 0;
    }
    if (a[al] != a[ar]) {
        cout << ar - al + 1 << endl;
        return 0;
    }
    int tl = al - 1, tr = ar + 1, tans = INT_MAX;
    for (; tl >= 1; --tl) 
        if (cl[a[tl]] == 1) break;
    if (tl > 0) tans = ar - tl + 1;
    for (; tr <= n; ++tr)
        if (cr[a[tr]] == 1) break;
    if (tr <= n) tans = min(tr - al + 1, tans);
    if (tl < 1 && tr > n) {
        cout << -1 << endl;
        return 0;
    }
    cout << tans << endl;
    return 0;
}
