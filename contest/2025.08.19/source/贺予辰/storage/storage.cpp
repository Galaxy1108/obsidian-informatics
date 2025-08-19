#include<bits/stdc++.h>
#define valt long double
#define int long long
using namespace std;
int f[1000006], q[1000006], h = 1, t = 1;
int xs[1000006], ps[1000006], c[1000006], n;
int v[1000006];
void pre() {
    memset(q, 0, sizeof(q));
    memset(f, 0, sizeof(f));
    v[0] = xs[0] = ps[0] = 0;
    for (int i = 1; i <= n; ++i) {
        ps[i] += ps[i - 1];
        int x = xs[i] - xs[i - 1];
        v[i] = v[i - 1] + x * ps[i - 1];
    }
}
valt X(int j) {
    return ps[j];
}
valt Y(int j) {
    return f[j] + ps[j] * xs[j] - v[j];
}
valt K(int i) {
    return xs[i];
}
valt slope(int j0, int j1) {
    return (Y(j1) - Y(j0)) / (X(j1) - X(j0));
}
signed main() {
    freopen("storage.in", "r", stdin);
    freopen("storage.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> xs[i] >> ps[i] >> c[i];
    pre();
    for (int i = 1; i <= n; ++i) {
        while (h < t && slope(q[h], q[h + 1])
        <= K(i)) ++h;
        int j = q[h];
        f[i] = f[j] + ps[j] * xs[j] - v[j] -
        ps[j] * xs[i] + v[i] + c[i];
        while (h < t && slope(q[t - 1], q[t])
        >= slope(q[t], i)) --t;
        q[++t] = i;
    }
    cout << f[n] << '\n';
    return 0;
}
