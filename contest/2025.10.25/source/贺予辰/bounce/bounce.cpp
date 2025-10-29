#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 6, M = 2e1 + 1;
int n, q, t[N], a[N], rnk[N][M], op, m, lg, cnt;
bool fl[M];
void add(int p, int v) {
    cnt += v, a[p] += v;
    while (p <= n) t[p] += v, p += (p & -p);
}
int query(int p) {
    int ans = 0;
    for (int k = lg; k + 1; --k)
        if (t[ans | (1 << k)] < p)
            ans |= 1 << k,
            p -= t[ans];
    return ans + 1;
}
int main() {
    freopen("bounce.in", "r", stdin);
    freopen("bounce.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> q, lg = log2(n);
    for (int i = 1; i <= n; ++i) add(i, 1);
    for (int i = 2; i < M; ++i) {
        rnk[1][i] = 1;
        for (int p = 2; p <= n; ++p) {
            int k = (p - 1) / i + 1,
            j = p - k + 1 - rnk[p - k][i],
            f = (j - 1) / (i - 1) * i,
            g = (j - 1) % (i - 1) + 2;
            rnk[p][i] = f + g;
        }
    }
    while (q--) {
        cin >> op >> m;
        if (op == 1 && !fl[m]) {
            fl[m] = 1;
            for (int p = 1; p <= n; p += m)
                if (a[p]) add(p, -1);
        } else if (op == 2)
            for (int p = 1; p <= cnt; p += m - 1) 
                add(query(p), -1);
        else if (op == 3) {
            if (!cnt) cout << -1 << '\n';
            else cout <<
                query(rnk[cnt][m]) << '\n';
        }
    }
    return 0;
}