#include<bits/stdc++.h>
using namespace std;
int n, q, a[200005], opt, l, ll;
int query(int L, int R) {
    if (L == R) return a[L];
    int M = (L + R - 1) >> 1;
    int t0 = query(L, M), t1 = query(M + 1, R);
    return max(t0, t1) - min(t0, t1);
}
int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    while (q--) {
        cin >> opt >> l >> ll;
        if (opt == 1) a[l] = ll;
        else cout << query(l, l + (1 << ll) - 1) << '\n';
    }
    return 0;
}