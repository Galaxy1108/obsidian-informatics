#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, s1[2001], s2[2001], ll[2001], rr[2001];
int sum1(int l, int r) {
    return s1[r] - s1[l - 1];
}
int sum2(int l, int r) {
    return s2[r] - s2[l - 1];
}
int a1(int p) {
    return s1[p] - s1[p - 1];
}
int a2(int p) {
    return s2[p] - s2[p - 1];
}
int max(int a, int b) {
    return a > b ? a : b;
}
signed main() {
    freopen("base.in", "r", stdin);
    freopen("base.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    s1[0] = s2[0] = 0;
    cin >> n;
    int ans = LONG_LONG_MIN;
    for (int i = 1; i <= n; ++i)
        cin >> s1[i], s1[i] += s1[i - 1];
    for (int i = 1; i <= n; ++i)
        cin >> s2[i], s2[i] += s2[i - 1];
    for (int i = 1; i <= n; ++i) {
        int nw, lst = a1(i) + a2(i);
        for (nw = ll[i] = i; nw; --nw)
            if (sum1(nw, i) + sum2(nw, i) > lst)
                ll[i] = nw, lst =
                sum1(nw, i) + sum2(nw, i);
        lst = a1(i) + a2(i);
        for (nw = rr[i] = i; nw <= n; ++nw)
            if (sum1(i, nw) + sum2(i, nw) > lst)
                rr[i] = nw, lst =
                sum1(i, nw) + sum2(i, nw);
    }
    for (int l = 1; l <= n; ++l)
        for (int r = l + 2; r <= n; ++r)
            ans = max(ans,
            sum1(ll[l], l) + sum2(ll[l], l) +
            sum1(r, rr[r]) + sum2(r, rr[r]) +
            sum2(l + 1, r - 1));
    cout << ans << '\n';
    return 0;
}