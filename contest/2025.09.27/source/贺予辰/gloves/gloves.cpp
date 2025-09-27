#include<bits/stdc++.h>
using namespace std;
int n, m, l[100005], r[100005];
bool check(int v) {
    int p = 0;
    for (int i = 1; i <= n; ++i) {
        ++p;
        while (abs(l[i] - r[p]) > v && p <= m)
            ++p;
        if (p > m) return 0;
    }
    return 1;
}
int main() {
    freopen("gloves.in", "r", stdin);
    freopen("gloves.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> l[i];
    for (int i = 1; i <= m; ++i)
        cin >> r[i];
    if (n > m) {
        for (int i = 1; i <= n; ++i)
            swap(l[i], r[i]);
        swap(n, m);
    }
    sort(l + 1, l + 1 + n), sort(r + 1, r + 1 + m);
    int L = 0, R = 1e9, ans = 1e9;
    while (L <= R) {
        int M = (L + R) >> 1;
        if (check(M)) ans = M, R = M - 1;
        else L = M + 1;
    }
    cout << ans << '\n';
    return 0;
}
